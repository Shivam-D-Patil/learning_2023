//Write a function to find biggest of 2 numbers using 
 //   - if else
  //  - ternary operator
  #include<stdio.h>
  int main()
  {
    int a,b;
    printf("enter 1st no\n");
    scanf("%d",&a);
    printf("enter 2nd no\n");
    scanf("%d",&b);
    if(a>b){
        printf("biggest of two no is a : %d \n",a);
    }else{
        printf("biggest of two no is b : %d\n",b);
    }

    //now using  ternary operator
    (a>b) ?(printf("biggest of two no is a : %d",a)) : (printf("biggest of two no is b : %d",b)) ;

    return 0;

  }