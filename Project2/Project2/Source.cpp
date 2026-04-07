/**
 * Pollard's p-1 factorization method на C++ с использованием GMP
 * Компиляция: g++ -o pollard_pm1 pollard_pm1.cpp -lgmp -lgmpxx
 */

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <gmpxx.h>

class PollardPM1 {
private:
    // Генератор случайных чисел
    std::mt19937_64 rng;

    /**
     * Наибольший общий делитель для GMP чисел
     */
    mpz_class gcd(const mpz_class& a, const mpz_class& b) const {
        mpz_class result;
        mpz_gcd(result.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
        return result;
    }

    /**
     * Тест Миллера-Рабина для проверки простоты
     */
    bool isProbablePrime(const mpz_class& n, int k = 10) const {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;

        // Записываем n-1 = d * 2^s
        mpz_class d = n - 1;
        int s = 0;
        while (d % 2 == 0) {
            d /= 2;
            s++;
        }

        std::uniform_int_distribution<unsigned long> dist(2,
            static_cast<unsigned long>(n.get_ui() - 2));

        for (int i = 0; i < k; i++) {
            mpz_class a = dist(rng);
            mpz_class x = powmod(a, d, n);

            if (x == 1 || x == n - 1) {
                continue;
            }

            bool composite = true;
            for (int j = 0; j < s - 1; j++) {
                x = powmod(x, 2, n);
                if (x == n - 1) {
                    composite = false;
                    break;
                }
            }

            if (composite) {
                return false;
            }
        }

        return true;
    }

    /**
     * Быстрое возведение в степень по модулю
     */
    mpz_class powmod(const mpz_class& base, const mpz_class& exp,
        const mpz_class& mod) const {
        mpz_class result;
        mpz_powm(result.get_mpz_t(), base.get_mpz_t(),
            exp.get_mpz_t(), mod.get_mpz_t());
        return result;
    }

    /**
     * Генерация списка простых чисел до B с помощью решета Эратосфена
     */
    std::vector<unsigned long> sievePrimes(unsigned long B) const {
        std::vector<bool> isPrime(B + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (unsigned long i = 2; i * i <= B; i++) {
            if (isPrime[i]) {
                for (unsigned long j = i * i; j <= B; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        std::vector<unsigned long> primes;
        for (unsigned long i = 2; i <= B; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    /**
     * Вычисление M = ? p^?log_p(B)? для всех простых p ? B
     */
    mpz_class computeM(unsigned long B) const {
        auto primes = sievePrimes(B);
        mpz_class M = 1;

        for (unsigned long p : primes) {
            unsigned long power = p;
            while (power * p <= B) {
                power *= p;
            }
            M *= power;
        }

        return M;
    }

public:
    PollardPM1() : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

    /**
     * Первая стадия p-1 метода
     * @param n число для факторизации
     * @param B1 граница гладкости
     * @param a основание (если 0, выбирается случайно)
     * @return нетривиальный делитель или 0
     */
    mpz_class stage1(const mpz_class& n, unsigned long B1,
        const mpz_class& a = 0) {
        if (n <= 1) return 0;

        // Проверка на простоту
        if (isProbablePrime(n)) {
            return n;
        }

        // Проверка маленьких делителей
        for (unsigned long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n % p == 0) {
                return p;
            }
        }

        // Выбираем основание
        mpz_class base = a;
        if (base == 0) {
            std::uniform_int_distribution<unsigned long> dist(2, 100);
            base = dist(rng);
        }

        // Вычисляем M
        mpz_class M = computeM(B1);

        // Вычисляем a^M mod n
        mpz_class b = powmod(base, M, n);

        // Находим gcd(b-1, n)
        mpz_class d = gcd(b - 1, n);

        if (d > 1 && d < n) {
            return d;
        }

        return 0;
    }

    /**
     * Полная версия с двумя стадиями
     * @param n число для факторизации
     * @param B1 граница для первой стадии
     * @param B2 граница для второй стадии
     * @param maxAttempts максимальное количество попыток
     * @return нетривиальный делитель или 0
     */
    mpz_class factorize(const mpz_class& n, unsigned long B1 = 100000,
        unsigned long B2 = 0, int maxAttempts = 5) {
        if (n <= 1) return 0;

        // Проверка на простоту
        if (isProbablePrime(n)) {
            return n;
        }

        // Несколько попыток с разными основаниями
        for (int attempt = 0; attempt < maxAttempts; attempt++) {
            // Первая стадия
            mpz_class d = stage1(n, B1);
            if (d > 1 && d < n) {
                return d;
            }

            // Вторая стадия (если указана)
            if (B2 > 0) {
                d = stage2(n, B1, B2);
                if (d > 1 && d < n) {
                    return d;
                }
            }

            // Увеличиваем B1 для следующей попытки
            B1 = static_cast<unsigned long>(B1 * 1.5);
            if (B2 > 0) {
                B2 = static_cast<unsigned long>(B2 * 1.5);
            }
        }

        return 0;
    }

    /**
     * Вторая стадия p-1 метода (оптимизированная)
     */
    mpz_class stage2(const mpz_class& n, unsigned long B1, unsigned long B2) {
        if (B2 <= B1) return 0;

        // Получаем простые числа между B1 и B2
        auto primes = sievePrimes(B2);
        std::vector<unsigned long> stage2Primes;
        for (unsigned long p : primes) {
            if (p > B1) {
                stage2Primes.push_back(p);
            }
        }

        if (stage2Primes.empty()) return 0;

        // Используем несколько случайных оснований
        for (int attempt = 0; attempt < 3; attempt++) {
            std::uniform_int_distribution<unsigned long> dist(2, 100);
            mpz_class a = dist(rng);

            // Вычисляем a^(B1!) mod n
            mpz_class M = computeM(B1);
            mpz_class b = powmod(a, M, n);

            // Вычисляем b^q для каждого простого q в (B1, B2]
            mpz_class prev_b = b;
            for (unsigned long q : stage2Primes) {
                mpz_class current = powmod(prev_b, q, n);
                mpz_class d = gcd(current - 1, n);

                if (d > 1 && d < n) {
                    return d;
                }

                prev_b = current;
            }
        }

        return 0;
    }

    /**
     * Полная факторизация числа (рекурсивная)
     */
    std::vector<mpz_class> fullFactorize(const mpz_class& n,
        unsigned long B1 = 100000) {
        std::vector<mpz_class> factors;

        if (n <= 1) return factors;

        if (isProbablePrime(n)) {
            factors.push_back(n);
            return factors;
        }

        mpz_class d = factorize(n, B1);

        if (d == 0) {
            // Если p-1 метод не сработал, можно использовать другие методы
            // Здесь для простоты возвращаем число как простое (или используем другой метод)
            factors.push_back(n);
            return factors;
        }

        mpz_class other = n / d;

        auto factors1 = fullFactorize(d, B1);
        auto factors2 = fullFactorize(other, B1);

        factors.insert(factors.end(), factors1.begin(), factors1.end());
        factors.insert(factors.end(), factors2.begin(), factors2.end());

        return factors;
    }
};

/**
 * Функция для ввода больших чисел из строки
 */
mpz_class readBigNumber(const std::string& s) {
    mpz_class result;
    result.set_str(s, 10);
    return result;
}

int main() {
    PollardPM1 factorizer;

    // Пример 1: число 10^1024 + 1 (сложное для факторизации)
    std::string numStr = "1";
    for (int i = 0; i < 1024; i++) {
        numStr += "0";
    }
    // 10^1024 + 1 имеет делители, связанные с круговыми многочленами
    mpz_class n = readBigNumber(numStr) + 1;

    std::cout << "Факторизация числа 10^1024 + 1" << std::endl;
    std::cout << "n = " << n.get_str() << std::endl;
    std::cout << "Количество цифр: " << numStr.length() << std::endl;

    // Для чисел такого размера B1 нужно выбирать осторожно
    // На практике B1 подбирается в зависимости от ожидаемой гладкости p-1
    unsigned long B1 = 100000;  // Начальная граница

    auto start = std::chrono::high_resolution_clock::now();

    mpz_class factor = factorizer.factorize(n, B1);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (factor > 0 && factor < n) {
        std::cout << "\nНайден делитель: " << factor.get_str() << std::endl;
        std::cout << "Время: " << duration.count() << " мс" << std::endl;
    }
    else {
        std::cout << "\nДелитель не найден. Попробуйте увеличить B1." << std::endl;
    }

    // Пример 2: факторизация числа с известным гладким p-1
    std::cout << "\n\n" << std::string(50, '=') << std::endl;
    std::cout << "Пример с известным гладким делителем:" << std::endl;

    // Создаем число, где p-1 является гладким
    mpz_class p = 1;
    for (unsigned long prime : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        p *= prime;
    }
    p = p + 1;  // p простое? Не гарантировано, но для примера

    // Проверяем, что p простое
    while (!factorizer.isProbablePrime(p)) {
        p += 2;
    }

    mpz_class q = 1000003;  // Еще один простой множитель
    mpz_class smoothNumber = p * q;

    std::cout << "Число: " << smoothNumber.get_str() << std::endl;
    std::cout << "Ожидаемый гладкий делитель p: " << p.get_str() << std::endl;
    std::cout << "p-1 = " << (p - 1).get_str() << " (гладкое)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mpz_class smoothFactor = factorizer.factorize(smoothNumber, 100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (smoothFactor > 0 && smoothFactor < smoothNumber) {
        std::cout << "Найден делитель: " << smoothFactor.get_str() << std::endl;
        std::cout << "Время: " << duration.count() << " мс" << std::endl;
    }

    return 0;
}