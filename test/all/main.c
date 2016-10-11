#include <stdio.h>
#include <string.h>

int main(){
    int numb1=0,numb2=0,numb3=0,numb4=0, mask=0;
    FILE *in, *out;
    char string[20];

    in=fopen("input.dat", "r");
    if(!in){
        printf("error open file.");
        return 1;
    }
    out=fopen("output.dat","w");
    if(!in){
        printf("error open file2.");
        return 1;
    }

    while(fscanf(in,"%s", string)!=EOF){
        sscanf(string,"%d.%d.%d.%d/%d",&numb1,&numb2,&numb3,&numb4,&mask);

        if(numb1>0  && numb1<255 &&
            numb2>=0 && numb2<=255 &&
            numb3>=0 && numb3<=255 &&
            numb4>0  && numb4<255 &&
            mask>=0  && mask<=32){
            fprintf(out,"%s",string);
        }
        numb1=0;
        numb2=0;
        numb3=0;
        numb4=0;
        mask=0;

    }

   fclose(in);
   fclose(out);

    return 0;
}


















































//#include <stdio.h>
//#include <string.h>

//int main(){
//    int numb1,numb2,numb3,numb4,numb5=-1;
//    char s[]="12.128.5.10/5";
//    //printf("%s\n",s);


//    sscanf(s,"%d.%d.%d.%d/%d",&numb1,&numb2,&numb3,&numb4,&numb5);

//    printf("5=%d\n", numb5);

//    if(numb1>0  && numb1<255 &&
//       numb2>=0 && numb2<=255 &&
//       numb3>=0 && numb3<=255 &&
//       numb4>0  && numb4<255){
//        printf("all good");
//    } else {
//        printf("error");
//    }
//    numb1=0;
//    numb2=0;
//    numb3=0;
//    numb4=0;
//    numb5=-1;

//    if(numb5){
//        printf("!!!!!!!!!!");
//    } else {
//        printf("_________________________");
//    }



//    printf("\n%s\n",s);
//    //printf("%d %d %d %d\n",numb1,numb2,numb3,numb4);


//return 0;
//}













































//#include <stdio.h>
//#include <string.h>

//int main(){
//    int n, number, count=0, i=0, flag;
//    char str[]="12.168.125.10/15";
//    char str_temp[]={0};
//    char cutSumbol[]="/.";
//    char *pstr;
//    //printf("%s\n",s);
//    //printf("%c",s[1]);


//    printf("out string: %s\n",str);
//    printf("resault:\n");

//    memcpy(str_temp,str,sizeof(str));
//    printf("!!!!!!!!!!!!out string: %s\n",str);
//    printf("temp=%s\n",str_temp);

//    pstr=strtok(str_temp,cutSumbol);

//    printf("!!!!!!!!!!!!out string: %s\n",str);
//    printf("temp=%s\n",str_temp);


////    flag=0;
////    while(pstr!=NULL){
////        printf("%s\n",pstr);
////        sscanf(pstr,"%d",&number);
////        printf("number=%d\n",number);
////        if(number<1 || number>255){
////            flag++;
////            break;
////        }
////        pstr=strtok(NULL,cutSumbol);
////    }
////    if(flag==0){
////        printf("out string: %s\n",str);
////    }

//    return 0;
//}
