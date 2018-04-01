#include <stdio.h> 
#define max 300 

int in[max];                                              //creating a global array to implement stack
int op[max];                                              //creating a global array to implement stack 
int topi = -1; 
int topo = -1; 

int isemptyi(){                                              //creating various function to for implementing stack
        if(topi == -1){ 
                return 1; 
        }else{ 
                return 0; 
        }
}

int isfulli(){                                               
        if(topi == max -1){  
                return 1; 
        }else{ 
                return 0; 
        }       
}

void pushi(int x) {                                         //to push an element in stack
     if(isfulli() == 1){ 
        return;     
     }else{
     topi = topi + 1; 
     in[topi] = x;  
     return;} 
}

void popi(){                                                //to pop an element from stack 
    if(isemptyi() == 1){ 
        return; 
    }else{
    topi = topi -1; 
    return;
    }
}
int isemptyo(){
        if(topo == -1){
                return 1;
        }else{
                return 0;
        }
}

int isfulo(){
        if(topo == max -1){
                return 1;
        }else{
                return 0;
        }
}


void pusho(int x) {
         if(isfulo() == 1){
                return;
         }else{
         topo = topo + 1;
         op[topo] = x;
         return;}
}

void popo(){
        if(isemptyi() == 1){
                return;
        }else{
        topo = topo -1;
        return;
        }
}

void printstack(){                                                               //printing both the stacks
    int k = 0; 
    printf("operandstack  : ");
    for(k = 0; k <=topi; k++){ 
        printf("%d ", in[k]);
    }
    printf("\noperatorstack : ");
    for(k = 0; k <=topo; k++){ 
        printf("%c ", (char)op[k]);
    }
    printf("\n"); 
    return; 
}

int main(){ 
        char inputexpression[300]; 
        printf("\nenter expression\n");
        scanf("%s", inputexpression);                                  //taking expression as input from user                        
        int i = 0; 
        int finalsum = 0; 
        while(inputexpression[i] != '\0'){ 
                int y = 0;
        int c = 0; 
        int q = 0; 
        int locsaved = 0; 
        if((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){ 
                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){    //taking in the first integer
                        int x = ((int)inputexpression[i])-48; 
                        y *= 10; 
                        y += x; 
                        i++; 
                }
        pushi(y); 
        printstack();
        finalsum += y; 
        y = 0;
        } 
                if((int)inputexpression[i] == 40){                                       //checking if the next operand is bracket 
                c = 1; 
                locsaved = i-1; 
                i++;
                pusho(40);
                printstack(); 
                while((int)inputexpression[i] != 41){
                if((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                int x = ((int)inputexpression[i])-48;
                                        y *= 10;
                                        y += x;
                                        i++;
                                }
                                q = y; 
                                y = 0;
                pushi(q);
                }else{  
                                if((int)inputexpression[i] == 43){                                      //checking if the next operand is plus
                                i++;
                        pusho(43);
                        printstack();
                                int temp = 0;
                                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                        int x = ((int)inputexpression[i])-48;
                                        temp *= 10;
                                        temp += x;
                                        i++;
                        if(temp !=0){                    
                                q += temp;
                        pushi(temp);
                        }
                        } 
                        }else if((int)inputexpression[i] == 42){                              //checking if the next operand multiplication
                                i++;
                        pusho(42);
                        printstack();
                                int temp = 0;
                                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                        int x = ((int)inputexpression[i])-48;
                                        temp *= 10;
                                        temp += x;
                                        i++;
                                }
                                    if(temp != 0){ 
                            q *=temp;
                            pushi(temp);
                        }
                        }else if((int)inputexpression[i] == 47){                             //checking if the next operand is division
                                i++;
                        pusho(47);
                        printstack();
                                int temp = 1;
                                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                int x = ((int)inputexpression[i])-48;
                                temp *= 10;
                                temp += x;
                                i++;
                            }
                                   if(temp != 0) {
                        q /= temp;
                        pushi(temp);
                        }
                        }else if((int)inputexpression[i] == 45){                              //checking if the next operand is subtract
                                i++;
                        pusho(45);
                        printstack();
                                int temp = 0;
                                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                        int x = ((int)inputexpression[i])-48;
                                        temp *= 10;
                                        temp += x;
                                        i++;
                                }
                        if(temp !=0){
                                    q -= temp; 
                        pushi(temp);
                        }       
                        }}
            printstack(); 
                        }
            pusho(41);
            if((int)inputexpression[locsaved] == 43){ 
                finalsum += q;    
            }
            else if((int)inputexpression[locsaved] == 42){                       //doing the operation of bracket result with outside result
                finalsum *= q;    
            }
            else if((int)inputexpression[locsaved] == 47){ 
                finalsum /= q;    
            }
            else if((int)inputexpression[locsaved] == 45){ 
                finalsum -= q;    
            }
            else{ 
                finalsum+=q;
            }
                        i++; 
            printstack(); 
            topo = 0; 
            topi = 0; 
            pushi(q); 
            printstack();
                }
                else if((int)inputexpression[i] == 43){ 
            pusho(43);
            printstack();
            i++; 
            int temp = 0;                                       //checking the add operand and subsequent integer
                        while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){
                                int x = ((int)inputexpression[i])-48;
                                temp *= 10;
                                temp += x;
                                i++;
                        }
            if(temp != 0){
            pushi(temp);
            printstack(); 
                        finalsum += temp; 
            }
                }
                else if((int)inputexpression[i] == 42){
                pusho(42);
                printstack();
                i++;
                int temp = 0;                                                   //checking the multiply operand and subsequent integer
                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){ 
                        int x = ((int)inputexpression[i])-48;
                        temp *= 10;
                        temp += x;
                        i++;
                }
                    if(temp != 0) {
                    pushi(temp);
                    printstack();
                    finalsum *= temp;
                }
        }else if((int)inputexpression[i] == 47){
                pusho(47);                                                       //checking the divide operand and subsequent integer
                printstack();
                i++;
                int temp = 0;
                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){ 
                        int x = ((int)inputexpression[i])-48;
                        temp *= 10;
                        temp += x;
                        i++;
                }
                    if(temp != 0) {
                    pushi(temp);
                    printstack();
                    finalsum /= temp;
                }
        }else if((int)inputexpression[i] == 45){
                pusho(45);
                printstack();
                i++;
                int temp = 0;
                while((int)inputexpression[i] >= 48 && (int)inputexpression[i] <= 57){ 
                        int x = ((int)inputexpression[i])-48;
                        temp *= 10;
                        temp += x;
                        i++;
                }
                if(temp != 0){
                pushi(temp);
                printstack();                                                      //checking the subtract operand and subsequent integer
                finalsum -= temp;
            }
        } 
    if((topi > topo && c == 0)||topi-1 == topo){ 
        topo -= 1; 
        topi -= 2; 
        pushi(finalsum); 
        printstack();    
    }
    }
        printf("\nfinal sum = %d", finalsum);     
}