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

int fib_rec_int(int n, std::shared_ptr<int> pointer)
{
    try
    {
        std::cout << "fib_rec_int pointer count " << pointer.use_count() << std::endl;
        std::cout << "n " << n << std::endl;

        if (n > 10000)
        {
            throw new AppExcetion();
        }
        if (n < 3)
        {
            return 1;
        }
        else
        {
            return (fib_rec_int((n - 1), pointer) + fib_rec_int((n - 2), pointer));
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}


long fib_rec_long(int n, std::shared_ptr<int> pointer)
{
    try
    {
        std::cout << "fib_rec_long pointer count " << pointer.use_count() << std::endl;

        if (n > 10000)
        {
            throw new AppExcetion();
        }
        if (n < 3)
        {
            return 1;
        }
        else
        {
            return (fib_rec_long((n - 1), pointer) + fib_rec_long((n - 2), pointer));
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int fib_itr_int(int n, std::shared_ptr<int> pointer)
{
    int x0 = 0;
    int x1 = 1;

    try
    {
        std::cout << "fib_itr_int pointer count " << pointer.use_count() << std::endl;

        if (n > 10000)
        {
            throw new AppExcetion();
        }
        for (int i = 0; i < n; ++i)
        {
            int temp = x0 + x1;
            x0 = x1;
            x1 = temp;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return x0;
}

int main()
{
    int first_chosen_numer = 0;
    int second_chosen_numer = 0;
    int third_chosen_numer = 0;
    std::cout << "Podaj pierwszy numer do wyliczenia wyrazu ciagu fibonacciego " << std::endl;
    std::cin >> first_chosen_numer;
    std::cout << "Podaj drugi numer do wyliczenia wyrazu ciagu fibonacciego " << std::endl;
    std::cin >> second_chosen_numer;
    std::cout << "Podaj trzeci numer do wyliczenia wyrazu ciagu fibonacciego " << std::endl;
    std::cin >> third_chosen_numer;
    std::shared_ptr<int> shared = std::make_shared<int>();
    int result_fib_rec_int = fib_rec_int(first_chosen_numer, shared);
    long result_fib_rec_long = fib_rec_long(second_chosen_numer, shared);
    int result_fib_itr_int = fib_itr_int(third_chosen_numer, shared);
    std::cout << "result_fib_rec_int : " << result_fib_rec_int << std::endl;
    std::cout << "result_fib_rec_long : " << result_fib_rec_long << std::endl;
    std::cout << "result_fib_itr_int : " << result_fib_itr_int << std::endl;

    if (result_fib_rec_int != (int)result_fib_rec_long || result_fib_rec_int != result_fib_itr_int || result_fib_itr_int != (int)result_fib_rec_long)
    {
        std::cout << "Data is not correct" << std::endl;
    }
    else
    {
        int result = 0;
        bool first_check = false;
        bool second_check = false;
        bool third_check = false;

        if (result_fib_rec_int == (int)result_fib_rec_long)
        {
            result += 1;
            first_check = true;
        }

        if (result_fib_rec_int == result_fib_itr_int)
        {
            result += 1;
            second_check = true;
        }

        if ((int)result_fib_rec_long == result_fib_itr_int)
        {
            result += 1;
            third_check = true;
        }

        if (result >= 2)
        {
            if (first_check && second_check)
            {
                std::cout << "Result : " << result_fib_rec_int << std::endl;
            }
            else
            {
                if (first_check && third_check)
                {
                    std::cout << "Result : " << result_fib_rec_long << std::endl;
                }
                else
                {
                    std::cout << "Result : " << result_fib_itr_int << std::endl;
                }
            }
        }
    }

    return 0;
}