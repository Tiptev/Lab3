
#include <iostream>
#include <cctype>
//char alphabet_short[33] = {"а","б","в","г","д","е","ё","ж","з","и","й","к","л","м","н","о","п","р","с","т","у","ф","х","ц","ч","ш","щ","ъ","ы","ь","э","ю","я"};
//char alphabet_short[33] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
char alphabet_short[53] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
char word[1000];
int N ;

using namespace std;

int encrypt(char word[1000], char alphabet_short[53], int N)//функция шифрования введенного текста
{
    for(int s = 0; s < 1000; s++)//цикл для смены введненного символа
    {
        if (word[s] != '\0')//условие: не яляется ли введенный символ - /0, то есть не конец ли это ввденего текста?
        {
            for(int i = 0; i < 26; i++)//цикл для сравнения введненного текста с алфавитом
            {
                if(word[s] ==alphabet_short[i])//условие: соответствуют ли введенный символ - символу из алфавита
                {
                    word[s] = alphabet_short [i + N];//если сответствует, то введенному символу присваивается значения из алфавита с шагом N
                    break;
                }
            }
        }
        
    }    
    return 0;
}

int back_encrypt(char word[1000], char alphabet_short[53], int N)//цикл дешифрования введнего текста (аналогичен обычному шифрованию)
{
    for(int s = 0; s < 1000; s++)
    {
        if (word[s] != '\0')
        {
            for(int i = 51; i > 0; i--)
            {
                if(word[s] ==alphabet_short[i])
                {
                    word[s] = alphabet_short [i - N];
                    break;
                }
            }
        }
        
    }    
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
    cin.getline(word,1000);
    cout << "Введите шаг:  ";
    cin >> N;
    check(word);
    cout << "Защифрованное предложение: "; 
    encrypt(word, alphabet_short, N);
    check(word);
    cout << "Расшифрованное предложение: ";
    back_encrypt(word, alphabet_short, N);
    check(word);
    return 0;
}
