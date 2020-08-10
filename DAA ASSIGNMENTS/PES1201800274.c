#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char* intal_add(const char* intal1, const char* intal2){
	int x1=strlen(intal1);
	int x2=strlen(intal2);
	int max=x1;
	if(x2>x1){
		max=x2;
	}
	char* final=(char*)malloc(sizeof(char)*(max+2));
	x1--;
	x2--;		
	int rem=0;
	int i=0;
	while(i<=max){
		int y1=0;
		int y2=0;
		if(x1<0 && x2<0){
			if(rem==0){
			}
			else{
				rem=rem+48;				
				final[i++]= (char)rem;
				
			}
			break;
		}
		else{		
			if(x1>-1){
				y1=(int)intal1[x1--]-48;
			}
			if(x2>-1){
				y2=(int)intal2[x2--]-48;
			}
			int res=y1+y2+rem;
			int val=res%10 + 48;
			rem=res/10; 
			final[i++]=(char)val;
		}
	}
	int p=0;
	while(p<=(i-1)/2){
		char temp=final[p];
		final[p]=final[i-p-1];
		final[i-p-1]=temp;
		p++;
	}
	final[i]='\0';
	return final;
}
int intal_compare(const char* intal1, const char* intal2){
	int x1= strlen(intal1);
	int x2= strlen(intal2);
	if(x1>x2){
		return 1;
	}
	else if(x2>x1){
		return -1;
	}
	else{
		int i=0;
		while(i<x1){
			if((int)intal1[i]>(int)intal2[i]){
				return 1;
			}
			else if((int)intal1[i]<(int)intal2[i]){
				return -1;
			}
			i++;
		}
		return 0;
	}
}
char* intal_diff(const char* intal1, const char* intal2){
	if(intal_compare(intal1,intal2)==-1){
 		const char* temp = intal1;
		intal1 = intal2;	
		intal2 = temp;
	}
	int j=strlen(intal1);
	int k=strlen(intal2);
	int val;
	char* final=(char*)malloc(sizeof(char)*(j+2));
	int min=k;	
	j--;
	k--;	
	int i=0,rem=0;
	while(i<=min){
		int y1=0;
		int y2=0; 
		if(i==min){
			if(j!=k){					
				if(rem==1){
					while(intal1[j]=='0' && j>0){
						final[i++]=(char)57;
						j--;
					}
					if(j==0 && intal1[j]=='1'){
						break;
					}
					else{
						final[i++]=(char)intal1[j--]-1;
						while(j>-1){
							final[i++]=(char)intal1[j--];
						}
					}

				}
				else{
					while(j>-1){
						final[i++]=(char)intal1[j--];
					}
				}
			}
			else{				
				break;
			}
		}	
		else{			
			if(j>-1){
				y1=(int)intal1[j--]-48;
			}
			if(k>-1){
				y2=(int)intal2[k--]-48;
			}
			if(rem==1){
				y1=y1-rem;
			}
			if(y2>y1){
				rem=1;
				val= y1+10-y2+48;
				final[i++]=(char)val;
			}
			else{
				rem=0;
				val= y1-y2+48;
				final[i++]=(char)val;
			}
		}
	}
	i--;
	while(final[i]=='0' && i!=0){
		i--;
	}
	i++;
	int p=0;
	while(p<=(i-1)/2){
		char temp=final[p];
		final[p]=final[i-p-1];
		final[i-p-1]=temp;
		p++;
	}
	final[i]='\0';		
	return final;	
}
char* intal_fibonacci(unsigned int n){
	int count=1;
	char* first=(char*)malloc(sizeof(char)*1001); 
	first[0]='0';
	first[1]='\0';
	char* second=(char*)malloc(sizeof(char)*1001); 
	second[0]='1';
	second[1]='\0';	
	if(n==0){
		free(second);
		return first;
	}
	else if(n==1){
		free (first);
		return second;
	}
	else{
		while(count!=n){		
			char* temp2=intal_add(first,second);
			char* temp=first;
			char* temp3=second;
			first=temp3;
			second=temp2;
			count++;
			free(temp);			
		}
		free(first);
		return second;
	}
}
char* intal_multiply(const char* intal1, const char* intal2){
	int x1= strlen(intal1);
	int x2= strlen(intal2);
	char* final=(char*)malloc(sizeof(char)*((x1*x2)+2));
	char* prod=(char*)malloc(sizeof(char)*((x1*x2)+2));
	final[0]='0';
	final[1]='\0';
	int n= x2-1;	
	for(int j=0;j<x2;j++){
		int i=0;
		while(i<j){
			prod[i++]='0';
		}
		int rem=0;
		int y2=(int)intal2[n--]-48;
		int m= x1-1;
		for(int k=0;k<x1;k++){
			int y1=(int)intal1[m--]-48;
			int res= y1*y2+rem;
			int val= res%10 +48;
			rem= res/10;
			prod[i++]=(char)val;
		}
		if(rem!=0){
			rem=rem+48;
			prod[i++]=(char)rem;
		}
		int p=0;
		while(prod[i-1]=='0' && i>1){
			i--;
		}
		while(p<=(i-1)/2){
			char temp=prod[p];
			prod[p]=prod[i-p-1];
			prod[i-p-1]=temp;
			p++;
		}
		prod[i]='\0';
		char* temp =intal_add(prod,final);
		char* temp2=final;
		final=temp;
		free(temp2);	
	}
	free(prod);
	return final;
}
char* intal_factorial(unsigned int n){
	int count=0;
	char* final=(char*)malloc(sizeof(char)*1001);
	final[0]='1';
	final[1]='\0';
	if(n==0){
		return final;
	}
	char* var=(char*)malloc(sizeof(char)*1001);
	var[0]='1';
	var[1]='\0';
	while(count<n){
		char* temp1=final;
		char* temp2=var;
		char* temp3=intal_multiply(var,final);
		final=temp3;
		char* temp4=intal_add(var,"1");
		var= temp4;
		count++;
		free(temp1);
		free(temp2);
	}
	free(var);	
	return final;
}
int intal_min(char **arr, int n){
	char* final=arr[0];
	int i;
	int a=0;
	for(i=1;i<n;i++){
		int j=intal_compare(final,arr[i]);
		if(j==1){
			final=arr[i];
			a=i;
		}		
		
	}	
	return a;
}
int intal_max(char **arr, int n){
	char* final=arr[0];
	int i;
	int a=0;
	for(i=1;i<n;i++){
		int j=intal_compare(arr[i],final);		
		if(j==1){
			final=arr[i];
			a=i;
		}		
		
	}
	return a;
}
int intal_search(char **arr, int n, const char* key){	
	for(int i=0;i<n;i++){
		int j=intal_compare(arr[i],key);
		if(j==0){
			return i;
		}
	}
	return -1;
}
static char* substring(const char* intal1,int l, int* p){
	char* sub=(char*)malloc(sizeof(char)*(1001));
	int c=0;
	while (c < l) {
     		sub[c++] = intal1[(*p)++];	
   	}
	sub[c] = '\0';
	return sub;
} 
char* intal_mod(const char* intal1, const char* intal2){	
	if(intal_compare(intal1,intal2)==-1){
  		char *temp =(char*)malloc((strlen(intal1)+1) * sizeof(char));
		strcpy(temp, intal1);
  		return temp;
	}
	else if(intal_compare(intal1,intal2)==0){
		char *temp =(char*)malloc(2 * sizeof(char));
		strcpy(temp,"0");	
		return temp;
	}
	else{		
		int flag=0;		
		int p=0;
		int x=strlen(intal1);
		int y=strlen(intal2);
		char* sub=substring(intal1,y,&p);
		if(intal_compare(sub,intal2)==-1){
			sub=strncat(sub,&intal1[p++],1);
		}
		while(p<=x){
			while(intal_compare(sub,intal2)==1 ||intal_compare(sub,intal2)==0){
				char* temp=sub;
				char* temp1=intal_diff(sub,intal2);
				sub=temp1;
				free(temp);
			}
			while(intal_compare(sub,intal2)==-1){
				if(sub[0]=='0'){
					flag=1;
				}				
				if(p==x){
					return sub;
				}				
				sub=strncat(sub,&intal1[p++],1);
				if(flag==1){
					int i=0;
					while(sub[i]!='\0'){
						sub[i]=sub[i+1];
						i++;
					}
					flag=0;
				}
			}
		}		
	}			
}
static char* gcd(char* intal1, char* intal2){	
	char* temp="0";
	if(intal_compare(temp,intal2)==0){
		free(intal2);
		return intal1;
	}
	else{
		char* t=gcd(intal2,intal_mod(intal1,intal2));
		free(intal1);
		return t;
	}
}
char* intal_gcd(const char* intal1, const char* intal2){	
	char* temp1=(char*)malloc(sizeof(char)*(strlen(intal1)+2));
	strcpy(temp1,intal1);	
	char* temp2=(char*)malloc(sizeof(char)*(strlen(intal2)+2));
	strcpy(temp2,intal2);
	char* temp3=gcd(temp1,temp2);
	return temp3;		
}
int intal_binsearch(char **arr, int n, const char* key){
	int start=0;
	int end=n-1;
	while (start <= end) { 
	        int mid = (start+end)/ 2; 
        	if (intal_compare(arr[mid],key)==0){ 
            		return mid; 
  		}
        	else if (intal_compare(arr[mid],key)==-1){ 
            		start=mid+1; 
  		}
        	else{
            		end=mid-1; 
    		} 
	}
    	return -1; 
} 
char* intal_pow(const char *intal1,unsigned int n){ 
	char* zero="0";
	if(intal_compare(intal1,zero)==0){
		char *temp=(char*)malloc(sizeof(char)*2);
		temp[1]='\0';
		temp[0]='0';
		return temp;
	}	
	if (n == 0){ 
		char *temp=(char*)malloc(sizeof(char)*2);
		temp[1]='\0';
		temp[0]='1';
		return temp;
	} 
    	else if (n%2 == 0){ 
		char* temp=intal_pow(intal1, n/2);
		char* temp2=intal_multiply(temp,temp);
		free(temp);
		return (temp2);
		
	} 
    	else{
		char* temp=intal_pow(intal1, n/2);
		char* temp2=intal_multiply(temp,temp);
		free(temp);
		char* temp3=intal_multiply(intal1,temp2);
		free(temp2);
		return temp3;
	}  	
}
static void merge(char** arr, int start, int mid, int end) { 
    	int i, j, k; 
    	int n1 = mid - start + 1; 
    	int n2 =  end - mid; 
	char **L = (char**) malloc(n1 * sizeof(char*));
	char **R = (char**) malloc(n2 * sizeof(char*));
    	for (i = 0; i < n1; i++){ 
        	L[i] = arr[start + i];
	} 
    	for (j = 0; j < n2; j++){ 
        	R[j] = arr[mid + 1+ j];
	} 
    	i = 0; 
    	j = 0; 
    	k = start;  	
   	while (i < n1 && j < n2){ 
        	if (intal_compare(L[i],R[j])<=0){ 
        		arr[k] = L[i]; 
            		i++; 
        	} 
        	else{	 
            		arr[k] = R[j]; 
            		j++; 
        	} 
        	k++; 
    	} 
    	while (i < n1){ 
        	arr[k] = L[i]; 
        	i++; 
        	k++;
	}  
    	while (j < n2){ 
        	arr[k] = R[j]; 
        	j++; 
       		k++; 
    	}
	free(L);
	free(R); 
}   
static void mergesort(char** arr, int start, int end) { 
    if (start < end) {  
        int mid = start+(end-start)/2; 
        mergesort(arr, start, mid); 
        mergesort(arr, mid+1, end); 
        merge(arr, start, mid, end); 
    } 
} 
void intal_sort(char **arr, int n){
	mergesort(arr,0,n-1);
}
char* intal_bincoeff(unsigned int n, unsigned int k) 
{ 	
	if(n<k){
		char *temp=(char*)malloc(sizeof(char)*2);
		temp[1]='\0';
		temp[0]='0';
		return temp;
	}		
    	if(k>n/2){
		k=n-k;
    	}
    	char** C=(char**)malloc(sizeof(char*)*(k+1));
    	for(int a=1;a<=k;a++){
		C[a]=(char*) malloc(sizeof(char)*1001);
		C[a][0] = '0';
    		C[a][1] = '\0';
    	}	
    	C[0] = (char*) malloc(sizeof(char)*2);
    	C[0][0] = '1';
    	C[0][1] = '\0';
    	for (int i = 1; i <= n; i++){
		int min = k;
		if(i<min){
			min=i;
		}	 
        	for (int j = min;j > 0; j--){ 
	    		char* temp=C[j];
            		C[j] = intal_add(C[j],C[j-1]);
	    		free(temp);
		} 
    	}
    	char *result= malloc(sizeof(char)*(strlen(C[k])+1));
    	strcpy(result,C[k]); 
    	for(int m=0;m<k+1;m++){
		free(C[m]);
    	}
    	free(C);
    	return (result);
} 
char* coin_row_problem(char **arr, int n){
	int max=strlen(arr[0]);
	for (int i=1;i<n;i++){
		if(strlen(arr[i])>max){
			max=strlen(arr[i]);
		}
	}
	char* temp=(char*)malloc(sizeof(char)*(max+2));
	char* temp1=(char*)malloc(sizeof(char)*(max+2));
	char* temp2=(char*)malloc(sizeof(char)*(max+2));
	char* maxstr=(char*)malloc(sizeof(char)*(max+2)); 
	strcpy(temp,"0");
	strcpy(temp1,arr[0]);
	strcpy(temp2,temp1);
	for(int i=2;i<n+1;++i){
		char* temp3 = intal_add(arr[i-1],temp);
		if(intal_compare(temp3,temp1)==1){	
			strcpy(maxstr,temp3);
		}
		else{
			strcpy(maxstr,temp1);
		}
		strcpy(temp2,maxstr);
		free(temp3);
		strcpy(temp,temp1);
		strcpy(temp1,temp2);
	}
	char* final=(char*)malloc(sizeof(char)*(strlen(temp2)+1));
	strcpy(final,temp2);
	free(maxstr);
	free(temp);
	free(temp1);
	free(temp2);
	return final;
}

