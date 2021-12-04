#include <stdlib.h>
#include <iostream>
#include <exception>
#include <memory>

class AppExcetion : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Exception occured";
    }
};

int silnia_rec(int n, std::shared_ptr<int> pointer)
{
    try
    {
        std::cout << "silnia_rec pointer count " << pointer.use_count() << std::endl;

        if (n < 0)
        {
            throw new AppExcetion();
        }
        if (n > 10000)
        {
            throw new AppExcetion();
        }
        if (n < 2)
            return 1;

        return n * silnia_rec(n - 1, pointer);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return -1;
}

long silnia_rec_long(int n, std::shared_ptr<int> pointer)
{
    try
    {
        std::cout << "silnia_rec_long pointer count " << pointer.use_count() << std::endl;

        if (n < 0)
        {
            throw new AppExcetion();
        }
        if (n > 10000)
        {
            throw new AppExcetion();
        }
        if (n < 2)
            return 1;

        return n * silnia_rec_long(n - 1, pointer);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return -1;
}

int silnia_itr(int n, std::shared_ptr<int> pointer)
{
    int result = 1;
    try
    {
        std::cout << "silnia_itr pointer count " << pointer.use_count() << std::endl;

        if (n < 0)
        {
            throw new AppExcetion();
        }
        if (n > 10000)
        {
            throw new AppExcetion();
        }
        if (n == 0)
            return 1;
        else
        {
            while (n > 0)
            {
                result *= n;
                n--;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}

int main()
{
    int first_chosen_numer = 0;
    int second_chosen_numer = 0;
    int third_chosen_numer = 0;
    std::cout << "Podaj pierwsza liczbe do wyliczenia silni " << std::endl;
    std::cin >> first_chosen_numer;
    std::cout << "Podaj druga liczbe do wyliczenia silni " << std::endl;
    std::cin >> first_chosen_numer;
    std::cout << "Podaj trzecia liczbe do wyliczenia silni " << std::endl;
    std::cin >> first_chosen_numer;
    std::shared_ptr<int> shared = std::make_shared<int>();
    int result_silnia_rec = silnia_rec(first_chosen_numer, shared);
    long result_silnia_rec_long = silnia_rec_long(second_chosen_numer, shared);
    int result_silnia_intr = silnia_itr(third_chosen_numer, shared);

    if (result_silnia_rec != (int)result_silnia_rec_long || result_silnia_rec != result_silnia_intr || result_silnia_intr != (int)result_silnia_rec_long)
    {
        std::cout << "Brak poprawnosci danych" << std::endl;
    }
    else
    {
        int result = 0;
        bool first_check = false;
        bool second_check = false;
        bool third_check = false;

        if (result_silnia_rec == (int)result_silnia_rec_long)
        {
            result += 1;
            first_check = true;
        }

        if (result_silnia_rec == result_silnia_intr)
        {
            result += 1;
            second_check = true;
        }

        if ((int)result_silnia_rec_long == result_silnia_intr)
        {
            result += 1;
            third_check = true;
        }

        if (result >= 2)
        {
            if (first_check && second_check)
            {
                std::cout << "Result : " << result_silnia_rec << std::endl;
            }
            else
            {
                if (first_check && third_check)
                {
                    std::cout << "Result : " << result_silnia_rec_long << std::endl;
                }
                else
                {
                    std::cout << "Result : " << result_silnia_intr << std::endl;
                }
            }
        }
    }
    return 0;
}