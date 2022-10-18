#include <iostream>

using namespace std;

int main()
{
   setlocale(LC_ALL,"ru");
   bool menu1 = true;
   int menu;
   char num;
   int index=0;
   while(menu1)
   {
   cout<<"\nВыберите пункт меню: "<<endl
       <<"1.Числовой треугольник"<<endl
       <<"2.Нахождение биномиальных коэффициентов"<<endl
       <<"3.Вычисление среднего арифметического введеных точек"<<endl
       <<"4.Выход"<<endl;
    cin>>menu;
    switch(menu)
     {
        case 1:
        cout<<"Вы выбрали первый вариант"<<endl;
        {
          int n,k,height;
          cout<<"Введите высоту треугольника: "<<endl;
          cin>>height;
          for(n=0;n<=height;n++)
             {
              for(k=0;k<n;k++)
              cout<<k;
              cout<<endl;
             }
        }
        break;
        case 2:
        cout<<"Вы выбрали второй вариант"<<endl;
        {
            cout<<"Введите числа: "<<endl;
              int n, k;
              cin >> n;
              double j = 1;
              cout << j << " ";
              for (k = 0; k < n; k++)
              {
              cout << j * (n - k) / (k + 1 ) << endl;
              j = j  * (n -k) / (k + 1);
              }
        cout << endl; 
        }
        break;
        case 3:
        cout<<"Вы выбрали третий вариант"<<endl;
        {
         bool value = true;
         double e, l, q;
         cout << "Введите значения: " << endl;
         while (value) 
         {
         cin >> e;
         if (e == 0)
         {
            cout << endl;
            cout << l / q << endl;
            value = false;
         }
          l += e;
          q++;
         }
        }
        break;
        default:
            menu1 = false;
            break;
     }
    }
    return 0;
}