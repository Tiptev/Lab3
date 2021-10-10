#include <iostream>
#include <cctype>
char short_alphabet[53] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
char big_alphabet[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alphabet[53];
char word[1000];
int registr[1000]; 
int N;

using namespace std;

int encrypt(char word[1000], char short_alphabet[53],char big_alphabet[53], char alphabet[53], int N)//функция шифрования введенного текста
{
    for(int s = 0; s < 1000; s++)//цикл для смены введненного символа
    {
        if (word[s] != '\0')//условие: не яляется ли введенный символ - /0, то есть не конец ли это ввденего текста?
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
        
    }    
    return 0;
}

int back_encrypt(char word[1000], char short_alphabet[53],char big_alphabet[53], char alphabet[53], int N)//цикл дешифрования введнего текста (аналогичен обычному шифрованию)
{
    for(int s = 0; s < 1000; s++)
    {
        if (word[s] != '\0')
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
        
    }    
    return 0;
}

int remem_reg(char word[1000])
{
    for (int i = 0; i < 1000; i++)
    {
        if (islower(word[i]) == 0)
        {
            registr[i] = 1;
        }
    } 
    return 0;
}

int assignment_short(char short_alphabet[53],char alphabet[53])
{
    for (int i = 0; i < 53; i++)
        alphabet[i]=short_alphabet[i];
    return 0;
}

int assignment_big(char big_alphabet[53],char alphabet[53])
{
    for (int i = 0; i < 53; i++)
        alphabet[i]=big_alphabet[i];
    return 0;
}

int check(char word[1000])//
{
    cout<<endl;
    for (int h = 0; h < 1000; h++)
    {
    if (word[h]!='\0')
    cout << word[h];
    } 
    return 0;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    cout << "Введите предложение: ";
    cin.getline(word, 1000);
    cout << "Введите шаг:  ";
    cin >> N;
    cout << "Защифрованное предложение: ";
    assignment_short(short_alphabet, alphabet);
    encrypt(word, short_alphabet,big_alphabet,alphabet, N);
    assignment_big(big_alphabet,alphabet);
    encrypt(word, short_alphabet,big_alphabet,alphabet, N);
    check(word);
    cout << "Расшифрованное предложение: ";
    back_encrypt(word, short_alphabet,big_alphabet,alphabet, N);
    assignment_short(short_alphabet, alphabet);
    back_encrypt(word, short_alphabet,big_alphabet,alphabet, N);
    check(word);
    return 0;
}
