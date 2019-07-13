/*
 * https://leetcode.com/problems/print-in-order/
 */

#include <iostream>
#include <thread>
#include <functional>
#include <atomic>

using namespace std;

class Foo 
{
   atomic_int flag;

public:
   Foo() {
      flag = 0;
   }

   void first(function<void()> printFirst) 
   {
      // printFirst() outputs "first". Do not change or remove this line.
      printFirst();

      flag = 1;
   }

   void second(function<void()> printSecond) 
   {
      while (flag != 1);

      // printSecond() outputs "second". Do not change or remove this line.
      printSecond();

      flag = 2;
   }

   void third(function<void()> printThird) 
   {
      while (flag != 2);

      // printThird() outputs "third". Do not change or remove this line.
      printThird();
   }
};

void printFirst() 
{
   cout << "first";
}

void printSecond() 
{
   cout << "second";
}

void printThird() 
{
   cout << "third";
}

int main() 
{
   Foo foo;
   auto func = [&foo](void (Foo::*fp)(function<void()>), function<void()> p) -> void { (foo.*fp)(p); };

   thread t1(func, &Foo::first, printFirst);
   thread t2(func, &Foo::second, printSecond);
   thread t3(func, &Foo::third, printThird);
   t3.join();
   t1.join();
   t2.join();
   return 0;
}