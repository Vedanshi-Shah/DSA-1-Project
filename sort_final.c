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
	int checksort;
	int unique;
    int output;
    int ignore;
    int help;
}flags;
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
int myCompare_non_ignore(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}
int myCompare_ignore(const void* a, const void* b)
{
    return strcasecmp(*(const char**)a, *(const char**)b);
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
        printf("%d\n",l);
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
void sort(flags set,char *input_file_name,char *output_file_name){
    
    struct stat sb;
    stat(input_file_name,&sb);
    int SizeF=sb.st_size;
    int extSort=0;
    if(SizeF>=1000000){
        extSort=1;
    }
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
int main (int argc,char* argv[]){
	FILE *f;
	flags opt;
    opt.numeric=0;
    opt.reverse=0;
    opt.checksort=0;
    opt.unique=0;
    opt.output=0;
    opt.ignore=0;
	int c;

	while ((c = getopt (argc, argv, "nrcuof")) != -1){
    printf ("Option detected %d\n", c);
    switch (c)
    {
        case 'n':
            opt.numeric = 1;
            printf("Numeric flag detected\n");
            break;
        case 'r':
            opt.reverse=1;
            printf("Reverse flag detected\n");
            break;
        case 'c':
            opt.checksort=1;
            printf("Check flag detected\n");
            break;	
        case 'u':
            opt.unique=1;
            printf("Unique flag detected\n");
            break;
        case 'o':
            opt.output=1;
            printf("Output flag detected\n");
            break;
         case 'f':
            opt.ignore=1;
            printf("Ignore flag detected\n");
            break;		   	   	   
       case '?':
       	 printf("Invalid Option %c\n", optopt);
       	 exit (1);
	  }
    }
    
    if (argc-optind != 1) {
 		printf("Please specify exactly one input file\n");
 		exit (1);
	 }
	
	f = fopen(argv[optind], "r");
	if (f == NULL) {
		printf("File %s does not exist\n", argv[optind]);
		exit (1);
        fclose(f);
	}
    fclose(f);
    sort(opt,argv[optind],"result.txt");
    return 0;
}