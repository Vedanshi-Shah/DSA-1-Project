#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<ctype.h>
typedef struct flags{
	int numeric;
	int reverse;
	int unique;
    int output;
    int ignore;
    int help;
    int line;
}flags;
typedef struct Heap_float{
    float data;
    char *fileName;
    fpos_t address;
}Heap_ele_float;
typedef struct Heap_string{
    char *data;
    char *fileName;
    fpos_t address;
}Heap_ele_string;
Heap_ele_float heap_float[1000000];
Heap_ele_string heap_string[1000000];
int HeapSize_string;
int HeapSize_float;
void Init_string(){
    HeapSize_string=0;
    heap_string[0].data="";
    heap_string[0].fileName="";
}
void Insert_string(char *data,char *fileName,fpos_t address){
    HeapSize_string++;
    heap_string[HeapSize_string].data=(char *)malloc((strlen(data)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].data,data);
    heap_string[HeapSize_string].fileName=(char *)malloc((strlen(fileName)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].fileName,fileName);
    heap_string[HeapSize_string].address=address;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcmp(heap_string[i].data,temp.data)<0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
}
Heap_ele_string Delete_string(){
    Heap_ele_string res=heap_string[HeapSize_string];
    --HeapSize_string;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcmp(heap_string[i].data,temp.data)<0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
    return res;
}
void Insert_string_ignore(char *data,char *fileName,fpos_t address){
    HeapSize_string++;
    heap_string[HeapSize_string].data=(char *)malloc((strlen(data)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].data,data);
    heap_string[HeapSize_string].fileName=(char *)malloc((strlen(fileName)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].fileName,fileName);
    heap_string[HeapSize_string].address=address;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcasecmp(heap_string[i].data,temp.data)<0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
}
Heap_ele_string Delete_string_ignore(){
    Heap_ele_string res=heap_string[HeapSize_string];
    --HeapSize_string;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcasecmp(heap_string[i].data,temp.data)<0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
    return res;
}
void Insert_string_reverse(char *data,char *fileName,fpos_t address){
    HeapSize_string++;
    heap_string[HeapSize_string].data=(char *)malloc((strlen(data)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].data,data);
    heap_string[HeapSize_string].fileName=(char *)malloc((strlen(fileName)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].fileName,fileName);
    heap_string[HeapSize_string].address=address;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcmp(heap_string[i].data,temp.data)>0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
}
Heap_ele_string Delete_string_reverse(){
    Heap_ele_string res=heap_string[HeapSize_string];
    --HeapSize_string;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcmp(heap_string[i].data,temp.data)>0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
    return res;
}
void Insert_string_reverse_ignore(char *data,char *fileName,fpos_t address){
    HeapSize_string++;
    heap_string[HeapSize_string].data=(char *)malloc((strlen(data)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].data,data);
    heap_string[HeapSize_string].fileName=(char *)malloc((strlen(fileName)+1)*sizeof(char));
    strcpy(heap_string[HeapSize_string].fileName,fileName);
    heap_string[HeapSize_string].address=address;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcasecmp(heap_string[i].data,temp.data)>0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
}
Heap_ele_string Delete_string_reverse_ignore(){
    Heap_ele_string res=heap_string[HeapSize_string];
    --HeapSize_string;
    Heap_ele_string temp=heap_string[HeapSize_string];
    int k=HeapSize_string;
    for(int i=1;i<HeapSize_string;i++){
        if(strcasecmp(heap_string[i].data,temp.data)>0){
            k=i;
            temp=heap_string[i];
        }
    }
    if(k!=HeapSize_string){
        temp=heap_string[HeapSize_string];
        heap_string[HeapSize_string]=heap_string[k];
        heap_string[k]=temp;
    }
    return res;
}
void Init_float(){
    HeapSize_float=0;
    heap_float[0].data=0;
    heap_float[0].fileName="";
}
void Insert_float(float data,char *fileName,fpos_t address){
    HeapSize_float++;
    heap_float[HeapSize_float].data=data;
    heap_float[HeapSize_float].fileName=(char *)malloc((strlen(fileName)+1)*sizeof(char));
    strcpy(heap_float[HeapSize_float].fileName,fileName);
    heap_float[HeapSize_float].address=address;
    Heap_ele_float temp=heap_float[HeapSize_float];
    int k=HeapSize_float;
    for(int i=1;i<HeapSize_float;i++){
        if(heap_float[i].data<temp.data){
            k=i;
            temp=heap_float[i];
        }
    }
    if(k!=HeapSize_float){
        temp=heap_float[HeapSize_float];
        heap_float[HeapSize_float]=heap_float[k];
        heap_float[k]=temp;
    }
}
Heap_ele_float Delete_float(){
    Heap_ele_float res=heap_float[HeapSize_float];
    --HeapSize_float;
    Heap_ele_float temp=heap_float[HeapSize_float];
    int k=HeapSize_float;
    for(int i=1;i<HeapSize_float;i++){
        if(heap_float[i].data<temp.data){
            k=i;
            temp=heap_float[i];
        }
    }
    if(k!=HeapSize_float){
        temp=heap_float[HeapSize_float];
        heap_float[HeapSize_float]=heap_float[k];
        heap_float[k]=temp;
    }
    return res;
}
void Insert_float_reverse(float data,char *fileName,fpos_t address){
    HeapSize_float++;
    heap_float[HeapSize_float].data=data;
    heap_float[HeapSize_float].fileName=(char *)malloc((strlen(fileName)+1)*sizeof(char));
    strcpy(heap_float[HeapSize_float].fileName,fileName);
    heap_float[HeapSize_float].address=address;
    Heap_ele_float temp=heap_float[HeapSize_float];
    int k=HeapSize_float;
    for(int i=1;i<HeapSize_float;i++){
        if(heap_float[i].data>temp.data){
            k=i;
            temp=heap_float[i];
        }
    }
    if(k!=HeapSize_float){
        temp=heap_float[HeapSize_float];
        heap_float[HeapSize_float]=heap_float[k];
        heap_float[k]=temp;
    }
}
Heap_ele_float Delete_float_reverse(){
    Heap_ele_float res=heap_float[HeapSize_float];
    --HeapSize_float;
    Heap_ele_float temp=heap_float[HeapSize_float];
    int k=HeapSize_float;
    for(int i=1;i<HeapSize_float;i++){
        if(heap_float[i].data>temp.data){
            k=i;
            temp=heap_float[i];
        }
    }
    if(k!=HeapSize_float){
        temp=heap_float[HeapSize_float];
        heap_float[HeapSize_float]=heap_float[k];
        heap_float[k]=temp;
    }
    return res;
}
int count_lines(char *fileName){
    int l=0;
    FILE *In=fopen(fileName,"r");
    char str[1000];
    while(fgets(str,1000,In)){
        l++;
    }
    return l;
}
int compare_float (const void * a, const void * b)
{
    float fa = *(const float*) a;
    float fb = *(const float*) b;
    return (fa > fb) - (fa < fb);
}
int compare_float_reverse (const void * a, const void * b)
{
    float fa = *(const float*) a;
    float fb = *(const float*) b;
    return (fa < fb) - (fa > fb);
}
int myCompare_non_ignore(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}
int myCompare_ignore(const void* a, const void* b)
{
    return strcasecmp(*(const char**)a, *(const char**)b);
}
int myCompare_non_ignore_reverse(const void* a, const void* b)
{
    return strcmp(*(const char**)b,*(const char**)a);
}
int myCompare_ignore_reverse(const void* a, const void* b)
{
    return strcasecmp(*(const char**)b,*(const char**)a);
}
void float_display(float arr[],int len,int r){
    if(r==1){
        for(int i=len-1;i>=0;i--){
            if(((int)arr[i]-arr[i])==0){
                printf("%d\n",(int)arr[i]);
            }
            else{
                printf("%f\n",arr[i]);
            }
            
        }
    }
    else{
        for(int i=0;i<len;i++){
            if(((int)arr[i]-arr[i])==0){
                printf("%d\n",(int)arr[i]);
            }
            else{
                printf("%f\n",arr[i]);
            }
        }
    }
}
void string_display(char *arr[],int len,int r){
    if(r==1){
        for(int i=len-1;i>=0;i--){
            printf("%s\n",arr[i]);
        }
    }
    else{
        for(int i=0;i<len;i++){
            printf("%s\n",arr[i]);
        }
    }
}
void append_float(float arr[],int len,int r,char *outputFileName){
    FILE *Op=fopen(outputFileName,"w");
    if(r==1){
        for(int i=len-1;i>=0;i--){
            if(((int)arr[i]-arr[i])==0){
                fprintf(Op,"%d\n",(int)arr[i]);
            }
            else{
                fprintf(Op,"%f\n",arr[i]);
            }
        }
    }
    else{
        for(int i=0;i<len;i++){
            if(((int)arr[i]-arr[i])==0){
                fprintf(Op,"%d\n",(int)arr[i]);
            }
            else{
                fprintf(Op,"%f\n",arr[i]);
            }
        }
    }
    fclose(Op);
}
void string_append(char *arr[],int len,int r,char *outputFileName){
    FILE *Op=fopen(outputFileName,"w");
    if(r==1){
        for(int i=len-1;i>=0;i--){
            fprintf(Op,"%s\n",arr[i]);
        }
    }
    else{
        for(int i=0;i<len;i++){
            fprintf(Op,"%s\n",arr[i]);
        }
    }
    fclose(Op);
}
void print_sort_numeric(char *fileName,int r,int u){
    FILE *In=fopen(fileName,"r");
    if(In==NULL){
        printf("Cannot Open File!\n");
        return;
    }
    else{
        int l=count_lines(fileName);
        float arr[l];
        int j=0;
        char str[1000];
        while(fgets(str,1000,In)){
            if(str[strlen(str)-1]=='\n'){
                str[strlen(str)-1]='\0';
            }
            //printf("len: %ld\n",strlen(str));
            for(int z=0;str[z]!='\0' && z<strlen(str);z++){
                if(!(str[z]=='-' || str[z]=='.' || (str[z]>=48 && str[z]<=57) || (str[z]>=0 && str[z]<=31))){
                    //printf("char: %c\n",str[z]);
                    printf("Cannot be sorted numerically\n");
                    exit(0);
                }
            }
            arr[j]=atof(str);
            j++;
        }
        qsort (arr, l, sizeof(float), compare_float);
        if(u==1){
            int i=0;
            int k=0;
            float temp[l];
            while(i<l-1){
                if(arr[i]!=arr[i+1]){
                    temp[k++]=arr[i];
                }
                i++;
            }
            temp[k++]=arr[l-1];
            if(r==1){
                float_display(temp,k,1);
            }
            else{
                float_display(temp,k,0);
            }
        }
        else{
            if(r==1){
                float_display(arr,l,1);
            }
            else{
                float_display(arr,l,0);
            }
        }
    }
    fclose(In);
}
void print_sort_string(char *fileName,int r,int u,int i){
    FILE *In=fopen(fileName,"r");
    if(In==NULL){
        printf("Cannot Open File!\n");
        return;
    }
    if(i==1){
        //use ignore comparator
        int l=count_lines(fileName);
        //printf("%d\n",l);
        char *arr[l];
        arr[0]=(char *)malloc(sizeof(char)*1000);
        int j=0;
        while(fgets(arr[j],1000,In)){
            if(arr[j][strlen(arr[j])-1]=='\n'){
                arr[j][strlen(arr[j])-1]='\0';
            }
            j++;
            arr[j]=(char *)malloc(sizeof(char)*1000);
        }
        qsort(arr, l, sizeof(const char*), myCompare_ignore);
        if(u==1){
            int i=0;
            int k=0;
            char *temp[l];
            while(i<l-1){
                if(strcasecmp(arr[i],arr[i+1])!=0){
                    temp[k]=(char *)malloc((strlen(arr[i])+1)*sizeof(char));
                    strcpy(temp[k++],arr[i]);
                }
                i++;
            }
            temp[k]=(char *)malloc((strlen(arr[l-1])+1)*sizeof(char));
            strcpy(temp[k++],arr[i]);
            if(r==1){
                string_display(temp,k,1);
            }
            else{
                string_display(temp,k,0);
            }
        }
        else{
            if(r==1){
                string_display(arr,l,1);
            }
            else{
                string_display(arr,l,0);
            }
        }
    }
    else{
        //use normal comparator
        int l=count_lines(fileName);
        char *arr[l];
        arr[0]=(char *)malloc(sizeof(char)*1000);
        int j=0;
        while(fgets(arr[j],1000,In)){
            if(arr[j][strlen(arr[j])-1]=='\n'){
                arr[j][strlen(arr[j])-1]='\0';
            }
            j++;
            arr[j]=(char *)malloc(sizeof(char)*1000);
        }
        qsort(arr, l, sizeof(const char*), myCompare_non_ignore);
        if(u==1){
            int i=0;
            int k=0;
            char *temp[l];
            while(i<l-1){
                if(strcmp(arr[i],arr[i+1])!=0){
                    temp[k]=(char *)malloc((strlen(arr[i])+1)*sizeof(char));
                    strcpy(temp[k++],arr[i]);
                }
                i++;
            }
            temp[k]=(char *)malloc((strlen(arr[l-1])+1)*sizeof(char));
            strcpy(temp[k++],arr[i]);
            if(r==1){
                string_display(temp,k,1);
            }
            else{
                string_display(temp,k,0);
            }
        }
        else{
            if(r==1){
                string_display(arr,l,1);
            }
            else{
                string_display(arr,l,0);
            }
        }
    }
    fclose(In);
}
void append_sort_numeric(char *inputFileName,char *outputFileName,int r,int u){
    FILE *In=fopen(inputFileName,"r");
    if(In==NULL){
        printf("Cannot Open File!\n");
        return;
    }
    else{
        int l=count_lines(inputFileName);
        float arr[l];
        int j=0;
        char str[1000];
        while(fgets(str,1000,In)){
            if(str[strlen(str)-1]=='\n'){
                str[strlen(str)-1]='\0';
            }
            for(int z=0;str[z]!='\0' && z<strlen(str);z++){
                if(!(str[z]=='-' || str[z]=='.' || (str[z]>=48 && str[z]<=57) || (str[z]>=0 && str[z]<=31))){
                    //printf("char: %c\n",str[z]);
                    printf("Cannot be sorted numerically\n");
                    exit(0);
                }
            }
            arr[j]=atof(str);
            j++;
        }
        qsort (arr, l, sizeof(float), compare_float);
        if(u==1){
            int i=0;
            int k=0;
            float temp[l];
            while(i<l-1){
                if(arr[i]!=arr[i+1]){
                    temp[k++]=arr[i];
                }
                i++;
            }
            temp[k++]=arr[l-1];
            if(r==1){
                append_float(temp,k,1,outputFileName);
            }
            else{
                append_float(temp,k,0,outputFileName);
            }
        }
        else{
            if(r==1){
                append_float(arr,l,1,outputFileName);
            }
            else{
                append_float(arr,l,0,outputFileName);
            }
        }
    }
    fclose(In);
}
void append_sort_string(char *inputFileName,char *outputFileName,int r,int u,int i){
    FILE *In=fopen(inputFileName,"r");
    if(In==NULL){
        printf("Cannot Open File!\n");
        return;
    }
    if(i==1){
        //use ignore comparator
        int l=count_lines(inputFileName);
        //printf("%d\n",l);
        char *arr[l];
        arr[0]=(char *)malloc(sizeof(char)*1000);
        int j=0;
        while(fgets(arr[j],1000,In)){
            if(arr[j][strlen(arr[j])-1]=='\n'){
                arr[j][strlen(arr[j])-1]='\0';
            }
            j++;
            arr[j]=(char *)malloc(sizeof(char)*1000);
        }
        qsort(arr, l, sizeof(const char*), myCompare_ignore);
        if(u==1){
            int i=0;
            int k=0;
            char *temp[l];
            while(i<l-1){
                if(strcasecmp(arr[i],arr[i+1])!=0){
                    temp[k]=(char *)malloc((strlen(arr[i])+1)*sizeof(char));
                    strcpy(temp[k++],arr[i]);
                }
                i++;
            }
            temp[k]=(char *)malloc((strlen(arr[l-1])+1)*sizeof(char));
            strcpy(temp[k++],arr[i]);
            if(r==1){
                string_append(temp,k,1,outputFileName);
            }
            else{
                string_append(temp,k,0,outputFileName);
            }
        }
        else{
            if(r==1){
                string_append(arr,l,1,outputFileName);
            }
            else{
                string_append(arr,l,0,outputFileName);
            }
        }
    }
    else{
        //use normal comparator
        int l=count_lines(inputFileName);
        //printf("%d\n",l);
        char *arr[l];
        arr[0]=(char *)malloc(sizeof(char)*1000);
        int j=0;
        while(fgets(arr[j],1000,In)){
            if(arr[j][strlen(arr[j])-1]=='\n'){
                arr[j][strlen(arr[j])-1]='\0';
            }
            j++;
            arr[j]=(char *)malloc(sizeof(char)*1000);
        }
        qsort(arr, l, sizeof(const char*), myCompare_non_ignore);
        if(u==1){
            int i=0;
            int k=0;
            char *temp[l];
            while(i<l-1){
                if(strcmp(arr[i],arr[i+1])!=0){
                    temp[k]=(char *)malloc((strlen(arr[i])+1)*sizeof(char));
                    strcpy(temp[k++],arr[i]);
                }
                i++;
            }
            temp[k]=(char *)malloc((strlen(arr[l-1])+1)*sizeof(char));
            strcpy(temp[k++],arr[i]);
            if(r==1){
                string_append(temp,k,1,outputFileName);
            }
            else{
                string_append(temp,k,0,outputFileName);
            }
        }
        else{
            if(r==1){
                string_append(arr,l,1,outputFileName);
            }
            else{
                string_append(arr,l,0,outputFileName);
            }
        }
    }
    fclose(In);
}
void ext_float_sort(char *inputFileName,char *outputFileName,int r){
    printf("Sorting externally\n");
    Init_float();
    struct stat sb;
    stat(inputFileName,&sb);
    int SizeF=sb.st_size;
    int k=SizeF/102400;
    if(SizeF%102400!=0){
        k++;
    }
    FILE *In;
    int i=1;
    //int SizeF=0;
    char str[1000];
    if(r==0){
        FILE *Op=fopen(inputFileName,"r");
        while(i<=k){
            char tf[10];
            sprintf(tf,"%d",i);
            strcat(tf,".txt");
            In=fopen(tf,"w");
            stat(tf,&sb);
            int size_partF=sb.st_size;
            int line=0;
            while(size_partF<=102400 && fgets(str,1000,Op)){
                line++;
                if(str[strlen(str)-1]=='\n'){
                    str[strlen(str)-1]='\0';
                }
                for(int z=0;str[z]!='\0' && z<strlen(str);z++){
                    if(!(str[z]=='-' || str[z]=='.' || (str[z]>=48 && str[z]<=57) || (str[z]>=0 && str[z]<=31))){
                        printf("Cannot be sorted numerically\n");
                        exit(0);
                    }
                }
                char *data=(char *)malloc((strlen(str)+1)*sizeof(char));
                strcpy(data,str);
                fprintf(In,"%s\n",data);
                stat(tf,&sb);
                size_partF=sb.st_size;
            }
            fclose(In);
            stat(tf,&sb);
            if(sb.st_size==0){
                break;
            }
            float arr[line];
            In=fopen(tf,"r");
            int j=0;
            while(fgets(str,1000,In)){
                if(str[strlen(str)-1]=='\n'){
                    str[strlen(str)-1]='\0';
                }
                arr[j]=atof(str);
                j++;
            }
            qsort (arr, line, sizeof(float), compare_float);
            fclose(In);
            In=fopen(tf,"w");
            fpos_t pos;
            fprintf(In,"%f\n",arr[0]);
            fgetpos(In,&pos);
            char *filen=(char *)malloc((strlen(tf)+1)*sizeof(char));
            strcpy(filen,tf);
            Insert_float(arr[0],filen,pos);
            for(int p=1;p<line;p++){
                fprintf(In,"%f\n",arr[p]);
            }
            fclose(In);
            i++;
        }
        int n_of_chunks=i;
        fclose(Op);
        Op=fopen(outputFileName,"a");
        float data;
        while(HeapSize_float>0){
            Heap_ele_float res=Delete_float();
            data=res.data;
            if(((int)res.data-res.data)==0){
                fprintf(Op,"%d\n",(int)data);
            }
            else{
                fprintf(Op,"%f\n",data);
            }
            fpos_t posi;
            In=fopen(res.fileName,"r");
            fsetpos(In,&res.address);
            fgets(str,1000,In);
            fgetpos(In,&posi);
            fsetpos(In,&res.address);
            if(getc(In)!=EOF){
                if(str[strlen(str)-1]=='\n'){
                    str[strlen(str)-1]='\0';
                }
                Insert_float(atof(str),res.fileName,posi);
            }
            fclose(In);
        }
        fclose(Op);
        for(int nc=1;nc<=n_of_chunks;nc++){
            char tf[10];
            sprintf(tf,"%d",nc);
            strcat(tf,".txt");
            remove(tf);
        }
    }
    else{
        FILE *Op=fopen(inputFileName,"r");
        while(i<=k){
            char tf[10];
            sprintf(tf,"%d",i);
            strcat(tf,".txt");
            In=fopen(tf,"w");
            stat(tf,&sb);
            int size_partF=sb.st_size;
            int line=0;
            while(size_partF<=102400 && fgets(str,1000,Op)){
                line++;
                if(str[strlen(str)-1]=='\n'){
                    str[strlen(str)-1]='\0';
                }
                for(int z=0;z<strlen(str);z++){
                    if(!(str[z]>=48 && str[z]<=57)){
                        printf("Cannot be sorted numerically\n");
                        exit(0);
                    }
                }
                char *data=(char *)malloc((strlen(str)+1)*sizeof(char));
                strcpy(data,str);
                fprintf(In,"%s\n",data);
                stat(tf,&sb);
                size_partF=sb.st_size;
            }
            fclose(In);
            stat(tf,&sb);
            if(sb.st_size==0){
                break;
            }

            float arr[line];
            In=fopen(tf,"r");
            int j=0;
            while(fgets(str,1000,In)){
                if(str[strlen(str)-1]=='\n'){
                    str[strlen(str)-1]='\0';
                }
                arr[j]=atof(str);
                j++;
            }
            qsort (arr, line, sizeof(float), compare_float_reverse);
            fclose(In);
            In=fopen(tf,"w");
            fpos_t pos;
            fprintf(In,"%f\n",arr[0]);
            fgetpos(In,&pos);
            char *filen=(char *)malloc((strlen(tf)+1)*sizeof(char));
            strcpy(filen,tf);
            Insert_float_reverse(arr[0],filen,pos);
            for(int p=1;p<line;p++){
                fprintf(In,"%f\n",arr[p]);
            }
            fclose(In);
            i++;
        }
        int n_of_chunks=i;
        fclose(Op);
        Op=fopen(outputFileName,"a");
        float data;
        while(HeapSize_float>0){
            Heap_ele_float res=Delete_float_reverse();
            data=res.data;
            if(((int)res.data-res.data)==0){
                fprintf(Op,"%d\n",(int)data);
            }
            else{
                fprintf(Op,"%f\n",data);
            }
            
            fpos_t posi;
            In=fopen(res.fileName,"r");
            fsetpos(In,&res.address);
            fgets(str,1000,In);
            fgetpos(In,&posi);
            fsetpos(In,&res.address);
            if(getc(In)!=EOF){
                if(str[strlen(str)-1]=='\n'){
                    str[strlen(str)-1]='\0';
                }
                Insert_float_reverse(atof(str),res.fileName,posi);
            }
            fclose(In);
        }
        fclose(Op);
        for(int nc=1;nc<=n_of_chunks;nc++){
            char tf[10];
            sprintf(tf,"%d",nc);
            strcat(tf,".txt");
            remove(tf);
        }
    }
}
void ext_string_sort(char *inputFileName,char *outputFileName,int I,int r){
    printf("Sorting externally\n");
    Init_string();
    struct stat sb;
    stat(inputFileName,&sb);
    int SizeF=sb.st_size;
    int k=SizeF/102400;
    if(SizeF%102400!=0){
        k++;
    }
    FILE *In;
    int i=1;
    //int SizeF=0;
    char str[1000];
    if(r==0){
        if(I==1){
            //call ignore non reverse functions
            FILE *Op=fopen(inputFileName,"r");
            while(i<=k){
                char tf[10];
                sprintf(tf,"%d",i);
                strcat(tf,".txt");
                In=fopen(tf,"w");
                stat(tf,&sb);
                int size_partF=sb.st_size;
                int line=0;
                while(size_partF<=102400 && fgets(str,1000,Op)){
                    line++;
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }
                    char *data=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(data,str);
                    fprintf(In,"%s\n",data);
                    stat(tf,&sb);
                    size_partF=sb.st_size;
                }
                fclose(In);
                stat(tf,&sb);
                if(sb.st_size==0){
                    break;
                }
                char *arr[line];
                In=fopen(tf,"r");
                int j=0;
                while(fgets(str,1000,In)){
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }

                    arr[j]=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(arr[j],str);
                    j++;
                }
                qsort (arr, line, sizeof(const char*),myCompare_ignore);
                fclose(In);
                stat(tf,&sb);
                if(sb.st_size==0){
                    break;
                }
                In=fopen(tf,"w");
                fpos_t pos;
                fprintf(In,"%s\n",arr[0]);
                fgetpos(In,&pos);
                char *filen=(char *)malloc((strlen(tf)+1)*sizeof(char));
                strcpy(filen,tf);
                Insert_string_ignore(arr[0],filen,pos);
                for(int p=1;p<line;p++){
                    fprintf(In,"%s\n",arr[p]);
                }
                fclose(In);
                i++;
            }
            int n_of_chunks=i;
            fclose(Op);
            Op=fopen(outputFileName,"w");
            char *data;
            while(HeapSize_string>0){
                Heap_ele_string res=Delete_string_ignore();
                data=(char *)malloc((strlen(res.data)+1)*sizeof(char));
                strcpy(data,res.data);
                if(data[strlen(data)-1]=='\n'){
                    data[strlen(data)-1]='\0';
                }
                fprintf(Op,"%s\n",data);
                fpos_t posi;
                In=fopen(res.fileName,"r");
                fsetpos(In,&res.address);
                fgets(str,1000,In);
                fgetpos(In,&posi);
                fsetpos(In,&res.address);
                if(getc(In)!=EOF){
                    char *di=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(di,str);
                    Insert_string_ignore(di,res.fileName,posi);
                }
                fclose(In);
            }
            fclose(Op);
            for(int nc=1;nc<=n_of_chunks;nc++){
                char tf[10];
                sprintf(tf,"%d",i);
                strcat(tf,".txt");
                remove(tf);
            }
        }
        else{
            //call non ignore non reverse functions
            FILE *Op=fopen(inputFileName,"r");
            while(i<=k){
                char tf[10];
                sprintf(tf,"%d",i);
                strcat(tf,".txt");
                In=fopen(tf,"w");
                stat(tf,&sb);
                int size_partF=sb.st_size;
                int line=0;
                while(size_partF<=102400 && fgets(str,1000,Op)){
                    line++;
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }
                    char *data=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(data,str);
                    fprintf(In,"%s\n",data);
                    stat(tf,&sb);
                    size_partF=sb.st_size;
                }
                fclose(In);
                stat(tf,&sb);
                if(sb.st_size==0){
                    break;
                }
                char *arr[line];
                In=fopen(tf,"r");
                int j=0;
                while(fgets(str,1000,In)){
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }

                    arr[j]=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(arr[j],str);
                    j++;
                }
                qsort (arr, line, sizeof(const char*),myCompare_non_ignore);
                fclose(In);
                In=fopen(tf,"w");
                fpos_t pos;
                fprintf(In,"%s\n",arr[0]);
                fgetpos(In,&pos);
                char *filen=(char *)malloc((strlen(tf)+1)*sizeof(char));
                strcpy(filen,tf);
                Insert_string(arr[0],filen,pos);
                for(int p=1;p<line;p++){
                    fprintf(In,"%s\n",arr[p]);
                }
                fclose(In);
                i++;
            }
            int n_of_chunks=i;
            fclose(Op);
            Op=fopen(outputFileName,"w");
            char *data;
            while(HeapSize_string>0){
                Heap_ele_string res=Delete_string();
                data=(char *)malloc((strlen(res.data)+1)*sizeof(char));
                strcpy(data,res.data);
                if(data[strlen(data)-1]=='\n'){
                    data[strlen(data)-1]='\0';
                }
                fprintf(Op,"%s\n",data);
                fpos_t posi;
                In=fopen(res.fileName,"r");
                fsetpos(In,&res.address);
                fgets(str,1000,In);
                fgetpos(In,&posi);
                fsetpos(In,&res.address);
                if(getc(In)!=EOF){
                    char *di=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(di,str);
                    Insert_string(di,res.fileName,posi);
                }
                fclose(In);
            }
            fclose(Op);
            for(int nc=1;nc<=n_of_chunks;nc++){
                char tf[10];
                sprintf(tf,"%d",nc);
                strcat(tf,".txt");
                remove(tf);
            }
        }
        
    }
    else{
        //printf("reverse\n");
        if(I==1){
            //call ignore reverse functions
            
            FILE *Op=fopen(inputFileName,"r");
            while(i<=k){
                char tf[10];
                sprintf(tf,"%d",i);
                strcat(tf,".txt");
                In=fopen(tf,"w");
                stat(tf,&sb);
                int size_partF=sb.st_size;
                int line=0;
                while(size_partF<=102400 && fgets(str,1000,Op)){
                    line++;
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }
                    char *data=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(data,str);
                    fprintf(In,"%s\n",data);
                    stat(tf,&sb);
                    size_partF=sb.st_size;
                }
                fclose(In);
                char *arr[line];
                stat(tf,&sb);
                if(sb.st_size==0){
                    break;
                }
                In=fopen(tf,"r");
                int j=0;
                while(fgets(str,1000,In)){
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }

                    arr[j]=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(arr[j],str);
                    j++;
                }
                qsort (arr, line, sizeof(const char*),myCompare_ignore_reverse);
                fclose(In);
                In=fopen(tf,"w");
                fpos_t pos;
                fprintf(In,"%s\n",arr[0]);
                fgetpos(In,&pos);
                char *filen=(char *)malloc((strlen(tf)+1)*sizeof(char));
                strcpy(filen,tf);
                Insert_string_reverse_ignore(arr[0],filen,pos);
                for(int p=1;p<line;p++){
                    fprintf(In,"%s\n",arr[p]);
                }
                fclose(In);
                i++;
            }
            int n_of_chunks=i;
            fclose(Op);
            Op=fopen(outputFileName,"w");
            char *data;
            while(HeapSize_string>0){
                Heap_ele_string res=Delete_string_reverse_ignore();
                data=(char *)malloc((strlen(res.data)+1)*sizeof(char));
                strcpy(data,res.data);
                if(data[strlen(data)-1]=='\n'){
                    data[strlen(data)-1]='\0';
                }
                fprintf(Op,"%s\n",data);
                fpos_t posi;
                In=fopen(res.fileName,"r");
                fsetpos(In,&res.address);
                fgets(str,1000,In);
                fgetpos(In,&posi);
                fsetpos(In,&res.address);
                if(getc(In)!=EOF){
                    char *di=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(di,str);
                    Insert_string_reverse_ignore(di,res.fileName,posi);
                }
                fclose(In);
            }
            fclose(Op);
            for(int nc=1;nc<=n_of_chunks;nc++){
                char tf[10];
                sprintf(tf,"%d",nc);
                strcat(tf,".txt");
                remove(tf);
            }            
        }
        else{
            //call non ignore reverse functions
            FILE *Op=fopen(inputFileName,"r");
            while(i<=k){
                char tf[10];
                sprintf(tf,"%d",i);
                strcat(tf,".txt");
                In=fopen(tf,"w");
                stat(tf,&sb);
                int size_partF=sb.st_size;
                int line=0;
                while(size_partF<=102400 && fgets(str,1000,Op)){
                    line++;
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }
                    char *data=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(data,str);
                    fprintf(In,"%s\n",data);
                    stat(tf,&sb);
                    size_partF=sb.st_size;
                }
                fclose(In);
                stat(tf,&sb);
                if(sb.st_size==0){
                    break;
                }
                char *arr[line];
                In=fopen(tf,"r");
                int j=0;
                while(fgets(str,1000,In)){
                    if(str[strlen(str)-1]=='\n'){
                        str[strlen(str)-1]='\0';
                    }

                    arr[j]=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(arr[j],str);
                    j++;
                }
                qsort (arr, line, sizeof(const char*),myCompare_non_ignore_reverse);
                fclose(In);
                In=fopen(tf,"w");
                fpos_t pos;
                fprintf(In,"%s\n",arr[0]);
                fgetpos(In,&pos);
                char *filen=(char *)malloc((strlen(tf)+1)*sizeof(char));
                strcpy(filen,tf);
                Insert_string_reverse(arr[0],filen,pos);
                for(int p=1;p<line;p++){
                    fprintf(In,"%s\n",arr[p]);
                }
                fclose(In);
                i++;
            }
            int n_of_chunks=i;
            fclose(Op);
            Op=fopen(outputFileName,"w");
            char *data;
            while(HeapSize_string>0){
                Heap_ele_string res=Delete_string_reverse();
                data=(char *)malloc((strlen(res.data)+1)*sizeof(char));
                strcpy(data,res.data);
                if(data[strlen(data)-1]=='\n'){
                    data[strlen(data)-1]='\0';
                }
                fprintf(Op,"%s\n",data);
                fpos_t posi;
                In=fopen(res.fileName,"r");
                fsetpos(In,&res.address);
                fgets(str,1000,In);
                fgetpos(In,&posi);
                fsetpos(In,&res.address);
                if(getc(In)!=EOF){
                    char *di=(char *)malloc((strlen(str)+1)*sizeof(char));
                    strcpy(di,str);
                    Insert_string_reverse(di,res.fileName,posi);
                }
                fclose(In);
            }
            fclose(Op);
            for(int nc=1;nc<=n_of_chunks;nc++){
                char tf[10];
                sprintf(tf,"%d",nc);
                strcat(tf,".txt");
                remove(tf);
            }
        }

    }
}
void External_Sort(flags set,char *inputFileName,char *outputFileName){
    if(set.output==0){
        printf("Please type a valid output filename\n");
        return;
    }
    FILE *In=fopen(inputFileName,"r");
    if(In==NULL){
        printf("Cannot Open File!\n");
        fclose(In);
        return;
    }
    //fclose(In);
    else{
        fclose(In);
        //append the elements
        if(set.numeric==1){
            //sort float
            if(set.reverse==1){
                //append reverse
                ext_float_sort(inputFileName,outputFileName,1);
            }
            else{
                //append ascending
                ext_float_sort(inputFileName,outputFileName,0);
            }
        }


        else{
            if(set.ignore==1){
                //check for lower case
                if(set.reverse==1){
                    //append in reverse order
                    ext_string_sort(inputFileName,outputFileName,1,1);
                }
                else{
                    //append in ascending order
                    ext_string_sort(inputFileName,outputFileName,1,0);
                }
            }
            else{
                //check normally
                if(set.reverse==1){
                    //append in reverse
                    ext_string_sort(inputFileName,outputFileName,0,1);
                }
                else{
                    //append in ascending
                    ext_string_sort(inputFileName,outputFileName,0,0);
                }
            }
        }
    }
}



void sort(flags set,char *input_file_name,char *output_file_name){
    if(set.line==1){
        FILE *In=fopen(input_file_name,"r");
        if(In==NULL){
            return;
        }
        printf("No. of Lines: %d\n",count_lines(input_file_name));
    }
    struct stat sb;
    stat(input_file_name,&sb);
    int SizeF=sb.st_size;
    int extSort=0;
    if(SizeF>=100000){
        extSort=1;
        External_Sort(set,input_file_name,output_file_name);
    }
    else{
        if(set.output==0){
            //print the output
            if(set.numeric==1){
                //numeric sort
                if(set.reverse==1){
                    //print in reverse
                    if(set.unique==1){
                        //print out unique elements
                        print_sort_numeric(input_file_name,1,1);
                    }
                    else{
                        //print out all
                        print_sort_numeric(input_file_name,1,0);
                    }
                }
                else{
                    //print in normal order
                    if(set.unique==1){
                        //print out unique elements
                        print_sort_numeric(input_file_name,0,1);
                    }
                    else{
                        //print out all
                        print_sort_numeric(input_file_name,0,0);
                    }
                }
            }



            else{
                //do the normal sort
                if(set.ignore==1){
                    //check with lower case
                    if(set.reverse==1){
                    //print in reverse
                        if(set.unique==1){
                            //print out unique elements
                            print_sort_string(input_file_name,1,1,1);
                        }
                        else{
                            //print out all
                            print_sort_string(input_file_name,1,0,1);
                        }
                    }
                    else{
                        //print in normal order
                        if(set.unique==1){
                            //print out unique elements
                            print_sort_string(input_file_name,0,1,1);
                        }
                        else{
                            //print out all
                            print_sort_string(input_file_name,0,0,1);
                        }
                    }
                }
                else{
                    //check normal
                    if(set.reverse==1){
                        //print in reverse
                        if(set.unique==1){
                            //print out unique elements
                            print_sort_string(input_file_name,1,1,0);
                        }
                        else{
                            //print out all
                            print_sort_string(input_file_name,1,0,0);
                        }
                    }
                    else{
                        //print in normal order
                        if(set.unique==1){
                            //print out unique elements
                            print_sort_string(input_file_name,0,1,0);
                        }
                        else{
                            //print out all
                            print_sort_string(input_file_name,0,0,0);
                        }
                    }
                }
            }
        }



        else{
            //printf("hey\n");
            //append the output to filename output_file_name
            if(set.numeric==1){
                //numeric sort
                if(set.reverse==1){
                    //append in reverse
                    if(set.unique==1){
                        //append out unique elements
                        append_sort_numeric(input_file_name,output_file_name,1,1);
                    }
                    else{
                        //append out all
                        append_sort_numeric(input_file_name,output_file_name,1,0);
                    }
                }
                else{
                    //append in normal order
                    if(set.unique==1){
                        //append out unique elements
                        append_sort_numeric(input_file_name,output_file_name,0,1);
                    }
                    else{
                        //append out all
                        append_sort_numeric(input_file_name,output_file_name,0,0);
                    }
                }
            }



            else{
                //do the normal sort
                if(set.ignore==1){
                    //check with lower
                    if(set.reverse==1){
                        //append in reverse
                        if(set.unique==1){
                            //append out unique elements
                            append_sort_string(input_file_name,output_file_name,1,1,1);
                        }
                        else{
                            //append out all
                            append_sort_string(input_file_name,output_file_name,1,0,1);
                        }
                    }
                    else{
                        //append in normal order
                        if(set.unique==1){
                            //append out unique elements
                            append_sort_string(input_file_name,output_file_name,0,1,1);
                        }
                        else{
                            //append out all
                            append_sort_string(input_file_name,output_file_name,0,0,1);
                        }
                    }
                }
                else{
                    //check normal
                    if(set.reverse==1){
                        //append in reverse
                        if(set.unique==1){
                            //append out unique elements
                            append_sort_string(input_file_name,output_file_name,1,1,0);
                        }
                        else{
                            //append out all
                            append_sort_string(input_file_name,output_file_name,1,0,0);
                        }
                    }
                    else{
                        //append in normal order
                        if(set.unique==1){
                            //append out unique elements
                            append_sort_string(input_file_name,output_file_name,0,1,0);
                        }
                        else{
                            //append out all
                            append_sort_string(input_file_name,output_file_name,0,0,0);
                        }
                    }
                }
            }
        }
    }
}
int main (int argc,char* argv[]){
    FILE* new_f;
    FILE* help;
	flags opt;
    opt.numeric=0;
    opt.reverse=0;
    opt.unique=0;
    opt.output=0;
    opt.ignore=0;
    opt.line=0;
    opt.help=0;
	int c;
	char outfilename[50];
	strcpy(outfilename, "\0");
	while ((c = getopt (argc, argv, "hnrulfo:")) != -1){
    //printf ("Option detected %d\n", c);
    switch (c)
    {
    	case 'h':
    		 opt.help=1;
    		 help=fopen("help_file.txt","r");
    		 char str[10000];
			 while(fgets(str,10000,help)){
			 	if(str[strlen(str)-1]=='\n'){
			 		str[strlen(str)-1]='\0';
				 }
			 	printf("%s\n",str);
			 }
			 fclose(help);
    		 exit(0);
        case 'n':
            opt.numeric = 1;
            //printf("Numeric flag detected\n");
            break;
        case 'r':
            opt.reverse=1;
            //printf("Reverse flag detected\n");
            break;
        case 'u':
            opt.unique=1;
            //printf("Unique flag detected\n");
            break;
          case 'f':
            opt.ignore=1;
            //printf("Ignore flag detected\n");
            break;
        case 'l':
            opt.line=1;
            //printf("Line flag detected\n");
            break;	    
        case 'o':
            opt.output=1;
            strcpy(outfilename,optarg);
            //printf("Output flag detected\n");
            //printf("%s\n",outfilename);
            break;
       	   	   	   
       case '?':
       	 printf("Invalid Option %c\n", optopt);
       	 exit (1);
	  }
    }
	int k=optind;
	new_f=fopen("merged.txt","a");
    if(argc-optind==0){
        printf("Please input a valid command\n");
        return 0;
    }
	if(argc-optind==1){
		 sort(opt,argv[optind],outfilename);
	}
	else{
        while(k<argc){
            char ele[100]="";
            FILE *f = fopen(argv[k], "r");
            if (f == NULL) {
                printf("File %s does not exist\n", argv[k]);
                exit (1);
                fclose(f);
            }
            else{
                while(fgets(ele,100,f)){
                    if(ele[strlen(ele)-1]=='\n'){
                        ele[strlen(ele)-1]='\0';
                    }
                    fprintf(new_f,"%s\n",ele);
                }
            }
            fclose(f);
            k++;
        }
        //printf("file created\n");
        fclose(new_f);
        if(new_f!=NULL){
            sort(opt,"merged.txt",outfilename);
            remove("merged.txt");
        }
	
    }
    return 0;
}
