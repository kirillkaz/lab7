#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

void pause_thread(int n)
{
    this_thread::sleep_for (chrono::milliseconds(n));
}

void ThreadsumArray(vector<int> array, int firstIndex, int secondIndex, int &sum){
    for (int i = firstIndex;i<=secondIndex;i++) sum+=array[i];
}

int main() {
    int N = 1000; //размер массива
    int sum = 0;
    vector<int> array;//сам массив
    array.resize(N);//задаю размер

    for (int i=0;i<N;i++)array[i] = i+1;//заполняю массив (получается это сумма всех чисел от 1 до 1000)
    //объявляю потоки
    thread thr1(ThreadsumArray,array,0,99,ref(sum));
    thread thr2(ThreadsumArray,array,100,199,ref(sum));
    thread thr3(ThreadsumArray,array,200,299,ref(sum));
    thread thr4(ThreadsumArray,array,300,399,ref(sum));
    thread thr5(ThreadsumArray,array,400,499,ref(sum));
    thread thr6(ThreadsumArray,array,500,599,ref(sum));
    thread thr7(ThreadsumArray,array,600,699,ref(sum));
    thread thr8(ThreadsumArray,array,700,799,ref(sum));
    thread thr9(ThreadsumArray,array,800,899,ref(sum));
    thread thr10(ThreadsumArray,array,900,999,ref(sum));
    //запускаю их отдельно (чтобы они работали одновременно)
    thr1.detach();
    thr2.detach();
    thr3.detach();
    thr4.detach();
    thr5.detach();
    thr6.detach();
    thr7.detach();
    thr8.detach();
    thr9.detach();
    thr10.detach();

    pause_thread(1);//пауза, чтобы return не сработал раньше времени
    cout<<sum<<endl;//вывожу сумму всех элементов массива
    return 0;
}
