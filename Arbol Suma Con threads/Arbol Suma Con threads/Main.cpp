#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>
using namespace std;

long funcx(int x)
{
    long sum = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            for (int k = 0; k < x; k++)
                sum += x;
    return sum;
}

void print_results(vector<long>& results, vector<chrono::duration<double>>& times)
{
    double max_time = 0;
    for (const auto& time : times)
        max_time = max(max_time, time.count());

    auto sum_total = 0;
    cout << "Resultados por thread:\n";
    for (int i = 0; i < 4; i++)
    {
        double percentage = (times[i].count() / max_time) * 100;
        cout << "Thread " << i + 1 << ": "
            << "Suma = " << results[i]
            << ", Tiempo = " << times[i].count()
            << " segundos (" << fixed << setprecision(2) << percentage << "%)\n";
        sum_total += results[i];
    }
    cout << "Suma total: " << sum_total << "\n";
}



void worker_x(int i, const vector<int>& arr, long& result, chrono::duration<double>& thread_time)
{
    auto t1 = chrono::high_resolution_clock::now();
    long local_sum = 0;
    int limite = (i + 1) * 50;
    for (i *= 50; i < limite; i++)
    {
        local_sum += funcx(arr[i]);
    }
    result = local_sum;
    auto t2 = chrono::high_resolution_clock::now();
    thread_time = t2 - t1;
}


void Sum_x(const vector<int>& arr)
{
    vector<long> results(4);
    vector<chrono::duration<double>> times(4);
    vector<thread> threads;
    for (int i = 0; i < 4; i++)
        threads.push_back(thread(worker_x,i, ref(arr), ref(results[i]), ref(times[i])));

    for (auto& th : threads)
        th.join();

    print_results(results, times);
}

int main()
{
    vector<int> arr = { 97,5,2,2,94,5,2,1,99,2,4,4,97,3,5,5,99,3,2,4,97,2,4,4,91,3,4,5,92,4,2,4,94,4,4,3,97,1,2,3,91,4,1,5,96,5,4,1,95,5,20,24,14,72,20,23,16,80,23,16,23,75,25,10,10,82,17,18,25,72,13,17,10,71,11,20,14,75,13,19,15,81,17,22,15,83,20,24,21,76,18,11,23,75,13,18,19,85,13,23,55,44,52,49,46,51,42,40,55,58,43,49,48,54,41,47,56,50,46,43,43,60,53,43,44,45,52,52,47,55,53,50,51,59,55,57,45,50,45,60,44,40,53,52,42,50,51,54,59,52,92,7,86,96,94,1,93,96,99,1,90,93,95,5,99,86,98,4,89,89,91,4,96,99,90,6,91,94,88,1,93,99,91,4,91,96,88,8,96,85,95,3,88,96,91,4,99,97,97,3 };

    Sum_x(arr);

    return 0;
}


