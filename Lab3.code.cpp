#include <iostream>
#include <cctype>
#include <cstring>
char short_alphabet[53] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
char big_alphabet[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alphabet[53], word[1024];
int N, length;
int choice;

using namespace std;

int encrypt(char word[1024], char alphabet[53], int N, int length)//функция шифрования введенного текста
{
    for(int s = 0; s < length; s++)//цикл для смены введненного символа
    {
            for(int i = 0; i < 26; i++)//цикл для сравнения введненного текста с алфавитом
            {
                if(word[s] ==alphabet[i])//условие: соответствуют ли введенный символ - символу из алфавита
                {
                    word[s] = alphabet[i + N];//если сответствует, то введенному символу присваивается значения из алфавита с шагом N
                    break;
                }
            }
    }    
    return 0;
}
int back_encrypt(char word[1024], char alphabet[53], int N, int length)//цикл дешифрования введнего текста (аналогичен обычному шифрованию)
{
    for(int s = 0; s < length; s++)
    {
            for(int i = 51; i > 0; i--)
            {
                if(word[s] ==alphabet[i])
                {
                    word[s] = alphabet[i - N];
                    break;
                }
            }
    }    
    return 0;
}
int assignment_short(char short_alphabet[53],char alphabet[53])//функция меняет регистр алфавита на маленький
{
    for (int i = 0; i < 53; i++)
        alphabet[i]=short_alphabet[i];
    return 0;
}
int assignment_big(char big_alphabet[53],char alphabet[53])//функция меняет регистр алфавита на большой
{
    for (int i = 0; i < 53; i++)
        alphabet[i]=big_alphabet[i];
    return 0;
}
int check(char word[1024])//функция выводит массив (введенный текст)
{
    cout<<endl;
    for (int h = 0; h < 1000; h++)
    {
    if (word[h]!='\0')
    cout << word[h];
    } 
    return 0;
}
int func_forward(char word[1024], char big_alphabet[53], char short_alphabet[53], char alphabet[53], int N, int lenght)
{//функция объединяет функции для процесса шифрования
    cout << "Защифрованное предложение: ";
    assignment_short(short_alphabet, alphabet);
    encrypt(word, alphabet, N, length);
    assignment_big(big_alphabet,alphabet);
    encrypt(word, alphabet, N, length);
    check(word); 
    return 0;
}
int func_back(char word[1024], char big_alphabet[53], char short_alphabet[53], char alphabet[53], int N, int lenght)
{//функция объединяет функции для процесса дешифрования
    cout << "Дешифрованное предложение: ";
    assignment_big(big_alphabet,alphabet);
    back_encrypt(word, alphabet, N, length);
    assignment_short(short_alphabet, alphabet);
    back_encrypt(word, alphabet, N, length);
    check(word);
   return 0; 
}
int main()
{   
    setlocale(LC_ALL, "rus");
    cout << "Введите предложение латинскими символами (до 1024 символов): ";
    cin.getline(word, 1024);
    length = strlen(word);//нахождение длинны введненого текста
    for (;;)//цикл контролирует правильные ли введены значения
    {
        cout << "Введите шаг сдвига (от 0 до 26): ";
        cin >> N;
        if ((N > 26) || (N < 0))
            cout << "Вы ввели шаг сдвига, не входящий в возможный интревал значений. \n ";
        else
            break;
    }
    for (;;)
    {
        cout << "Если вы хотите зашифровать текст - нажмите '1', если дешифровать нажмите - '0', если вы хотите закончить - нажмите '2'."<<endl;
        cout << "Ваш вариант : ";
        cin >> choice;
        if ((choice < 0) || (choice > 2))
            cout << "Вы ввели не правильное число!"<<endl;
        if(choice == 1)
            func_forward(word, big_alphabet, short_alphabet, alphabet, N, length);
        if (choice == 0)
            func_back(word, big_alphabet, short_alphabet, alphabet, N, length);
        if (choice == 2)
            break;
    }
    return 0;
}