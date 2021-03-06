
/*// Двійкові файли, що містять структури

#include <stdio.h>

struct Book {
    char aurhor[40];
    char title[80];
    int year;
    int pages;
};
int main(){
    struct Book b;
    struct Book *p;
    p=&b;
    p->year = 2005;

    printf("%d\n", b.year);

    struct Book a={
        "A.C.Pushkin",
        "Poltava",
        1998,
        5
    };

    printf("%s %s\n", a.aurhor, a.title);
    printf("%d\n",a.pages);

    return 0;
}
*/
/*// структура в текстовий файл (доступ по полях)
#include <stdio.h>
struct Book {
    char aurhor[40];
    char title[80];
    int year;
    int pages;
};

int main(){
    struct Book b;
    FILE *in;

    printf("author: ");
    gets(b.aurhor);
    printf("name book: ");
    gets(b.title);
    printf("year publikation, count pages ");
    scanf("%d%d",&b.year, &b.pages);

    in=fopen("library.txt", "a");
    if(!in){
        printf("error open file");
    }
    fprintf(in,"%s\n%s\n%d %d\n", b.aurhor, b.title, b.year, b.pages);
    fclose(in);

    return 0;
}
*/
/*// запис структури(як змінну) в бінарний файл
#include <stdio.h>
struct Book {
    char aurhor[40];
    char title[80];
    int year;
    int pages;
};

int main(){
    //int n;
    FILE *in;
     struct Book b;

    printf("author: ");
    gets(b.aurhor);
    printf("name book: ");
    gets(b.title);
    printf("year publikation, count pages ");
    scanf("%d%d",&b.year, &b.pages);

    in=fopen("library.dat", "ab");
    if(!in){
        printf("error open file");
    }
    fwrite(&b,sizeof(struct Book),1,in);
    fclose(in);

    return 0;
}
*/
/* task 1
#include <stdio.h>

struct Book {
    char aurhor[40];
    char title[80];
    int year;
    int pages;
};

int main(){

    struct Book b;
    int n=0;
    int num=0;

//    n=sizeof(struct Book);
//    printf("%d", n);

    FILE *in;
    in=fopen("library.dat", "rb");
    if(!in){
        printf("error open file");
    }


    for(num=0; num<6;num++){
    fseek(in,num*sizeof(struct Book), SEEK_SET);
    n=fread(&b,sizeof(struct Book),1,in);
    if(n==0){
        printf("error read file");
    }

    //printf("n=%d\n",n);
    printf("\n%s\n%s\n%d\n%d\n",b.aurhor,b.title,b.year,b.pages);
    }
    fclose(in);

    return 0;
}















/*main()
{
    struct Book my_book;
    struct Book* p=&my_book;


    FILE* fp;
    int n;

    fp = fopen("books1.dat", "rb"); // відкрити двійковий файл в режимі читання
    n = fread (p, sizeof(my_book), 1, fp); // зчитуємо з файлу блок даних
    //(кількість байт) величиною 1-ї структури за адресою p
    if ( n == 0 ) { // якщо нічого не зчиталося - помилка
        printf ( "File reading error!" );
        return;
    }
    fclose ( fp ); // закрити файл, з якого прочитали

    fp = fopen("books2.dat ", "ab"); // відкрити інший двійковий файл
    //в режимі дозапису
    fwrite(p, sizeof(my_book), 1, fp); // записуємо в кінець файлу блок даних
    //(кількість байт) величиною 1-ї структури
    fclose ( fp ); // закрити файл, в який записали
}

/* task 1.
1) відкрийте створений раніше текстовий файл з даними про клуби;
2) прочитайте по черзі дані про кожен клуб і одразу ж записуйте їх в двійковий файл teams.dat;
3)     відкрийте утворений файл в режимі читання і прочитайте з нього
довільні 3 структури (не в порядку запису!);
4)     прочитані дані запишіть у новий двійковий файл (наприклад, teams1.dat);
5)     новостворений файл відкрийте в режимі читання, вміст його виведіть на екран,
переконайтеся в коректності перенесення з іншого файлу даних.
*/

#include <stdio.h>

struct Book {
    char aurhor[40];
    char title[80];
    int year;
    int pages;
};

int main(){

    struct Book b[6];
    int n=0;
    int i=0;

//    n=sizeof(struct Book);
//    printf("%d", n);

    FILE *in;
    in=fopen("library.dat", "rb");
    if(!in){
        printf("error open file");
    }

    n=fread(&b[0],sizeof(struct Book),6,in);

    if(n==0){
        printf("error read file or empty file");
    }

   for(i=0;i<n;i++){
        printf("\n%s\n%s\n%d\n%d\n",b[i].aurhor,b[i].title,b[i].year,b[i].pages);
        printf("change numer pages olease:");
        scanf("%d",& b[i].pages);
   }
//   // print array
//   for(i=0;i<n;i++){
//        printf("array -\n%s\n%s\n%d\n%d\n",b[i].aurhor,b[i].title,b[i].year,b[i].pages);
//   }
    fclose(in);

    in=fopen("library_out.dat","w");
    if(!in){
        printf("error open library_out.dat");
    }
// printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!n=%d\n",n);
//   fwrite(b,sizeof(struct Book),n,in);
    for(i=0;i<n;i++){
        fwrite(b,sizeof(struct Book),n,in);
    }
   fclose(in);

   //------------------ output file
    in=fopen("library_out.dat", "rb");
    if(!in){
        printf("error open file");
    }
     n=fread(&b[0],sizeof(struct Book),6,in);
     if(n==0){
         printf("error read file or empty file");
     }

    for(i=0;i<n;i++){
         printf("\n%s\n%s\n%d\n%d\n",b[i].aurhor,b[i].title,b[i].year,b[i].pages);
    }

     return 0;
}
/*
// запис і читання з бінарного файлу масиву структур
#include <stdio.h>

struct Book {
    char author[40];
    char title[80];
    int year;
    int pages;
};

main()
{
    struct Book b[100]; 		// оголошуємо масив структур
    int i, n;
    FILE* fp; 			// дескриптор файлу

    fp = fopen("books.dat", "rb"); // відкрити файл в режимі читання
    n=fread(b, sizeof(Book), 100, fp); // читаємо з файлу 100 блоків
    // розміром однієї структури, і записуємо в пам’ять, починаючи з адреси b[0]
    fclose (fp);			// закриваємо файл
    for (i = 0; i < n; i ++) 	// в кожній з прочитаних n структур
        b[i].year = 2009; 	// змінюємо поле “рік видання”
    fp = fopen("books.dat", "wb"); // відкрити файл в режимі запису
    fwrite (b, sizeof(Book), n, fp);  // перезаписуємо зміст файлу зміненими
    // структурами в кількості n
    fclose (fp);			// закриваємо файл
}

/* task 2.
1) відкрийте в режимі читання двійковий файл структур, створений раніше;
2) прочитайте з нього всі структури у відповідний масив структур;
3) пройдіться по масиву в циклі, довільно (вручну) змінивши в кожній структурі
поле «місце» - при цьому в підсумку вони всі повинні бути різні, від 1 до 12;
4) в іншому циклі – запишіть змінені структури масиву в той самий двійковий файл,
але в порядку зайнятих місць, починаючи структурою з полем place ==1 і закінчуючи
структурою з полем place ==12.
5) виведіть вміст перезаписаного файлу на екран, переконайтесь в правильному
порядку розташування записів про клуби.
*/
