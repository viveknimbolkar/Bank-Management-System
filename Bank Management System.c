//This program is developed by Vivek Nimbolkar

#include<stdio.h>
#include<conio.h>
#include<windows.h>

void fordelay(int x);

int main()
{
	
	char ans[10]={'y','Y','0'},fst[50],md[50],sn[50],email[50];
	
	int i, action, pin, balance=1000, withdraw, dob, age, minus, add, afteradd, mono, pwd, rpwd,calc,c_ans;
	
	float princpal, interest,year,si,a,b;
	
	FILE *fp;
	
	printf("\t\t----------ATM & BANK MANAGEMENT SYSTEMN----------\t\t\n");
	//Enter pin
	printf("\nEnter your ATM card\n\n\t\tLoading\t");
	
	for(i=1;i<15;i++){
		fordelay(100000000);					//Loader
		printf(".");
	} 
	
	retype:
		
	printf("\n\nPlease Enter your pin= ");
	scanf("%d",&pin);
	
	restart:	                             //goto statement starting
	
	//If pin is true
	
	if(pin==1234){			//pin is 1234
		
		start:
			
			system("cls");
			
		printf("\t\t\t########## MAIN MENU ##########\n\n1) Balance Enquiry\n2) Cash withdrawl\n3) Cash Deposite\n4) Create new SBI account\n5) Interest calculator\n6) Calculator\n\n\n\t\t\tEnter your choice= ");
		
		scanf("%d",&action);
		
		switch(action){
			
			case 1:
				
				printf("\nYour account balance is Rs.%d\n \n\n\n\t\tDo you want to Exit? y/n ",balance);
		
				scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					fordelay(100000000);
					goto restart;	
				}
				else{
					goto end;
				}	
				break;
				
				
			case 2:
				
				system("cls");
				
				printf("\n\tYour current balance is Rs.%d \n\nEnter amount to withdraw= ",balance);
				
				scanf("%d",&withdraw);
				
				minus=balance-withdraw;   //formula
				
				if(minus>=100){
					
					printf("\nRs.%d is debited from your accound and your remaining balance is= Rs.%d\n", withdraw, minus);
				}	
				else
				 	printf("Insufficient amount!\n");
				
				printf("\n\n\t\tDo you want to Exit? y/n ");
				scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					fordelay(100000000);
					goto restart;		
				}
				else{
					goto end;
				}									
				break; 	
				
					
			case 3:
				
				system("cls");
				
				printf("\n\nEnter amount to Deposite= ",balance);
				
				scanf("%d",&add);
				
				balance=balance+add;     //formula
				
				printf("\n\t\tCash added successfully!\n\nNow, your current balance is Rs.%d\n\n\n\t\tnDo you want to Exit? y/n ",balance);
				
				scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					fordelay(100000000);
					goto restart;		
				}
				else{
					goto end;
				}
				break;
				
				
			case 4:
				
				system("cls");
				
				fp=fopen("record.txt","a+");
				
				
				printf("\nEnter first name:-");												//First name
				scanf("%s",&fst);
				
				printf("Enter father name:-");												//Father name
				scanf("%s",&md);
				
				printf("Enter sirname:-");													//Sirname
				scanf("%s",&sn);
				
				fprintf(fp,"\n\nAccount Holder Name:- %s %s %s \n",fst,md,sn);
				
				printf("Enter your email address:-");										//Email address		
				scanf("%s",&email);
				
				fprintf(fp,"Email:- %s\n",email);
				
				printf("Enter your aadhar link mobile no.:-");								//Mobile no.
				scanf("%d",&mono);
				
				printf("Enter your age:-");													//age
				scanf("%d",&age);
				
				fprintf(fp,"Age:- %d\n",age);
				
				printf("Enter date of birth(DOB):-");										//Dob
				scanf("%d",&dob);
				
				fprintf(fp,"Date of Birth:- %d\n",dob);
		
				Pin_return:								//pin rerurn
				
				printf("Create PIN:-\n\nPlease enter pin.");             //Pin						
				scanf("%d",&pwd);
				
				fprintf(fp,"PIN:- %d\n______________________________________________",pwd);	
							
				printf("\nRetype your PIN:-");
				scanf("%d",&rpwd);	
				
				fclose(fp);			
				
				
				if(pwd==rpwd){
					
					printf("\n\t\t\tPIN is successfully created. \n\nCreating account wait for a moment..");		//creating account
					
					int i;
					do{
						fordelay(100000000);
						printf(".");
						i++;
					}while(i<10);
					
					system("cls");
					
				    printf("\n\nAccount Holder Name=  %s %s %s \n\nEmail= %s \t\tMobile no= %d \t\t Age= %d \t\t \nDoB= %d \t\t Pin= %d",fst,md,sn,email,mono,age,dob,pwd);
				    
				}
				else
					{
						
					printf("\n\n\t\tPIN dosen't match or less than 5 character.\n");
					goto Pin_return;
				}			
				
				printf("\n\n\n\t\tDo you want to Exit?y/n ");
				scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					fordelay(100000000);
					goto restart;	
				}
				else{
					goto end;
				}
				break;
				
				
			case 5:
															//Interest calculator
				system("cls");
				
				printf("\nEnter principle amount= ");
				scanf("%f",&princpal);
				
				printf("\nEnter rate of interest= ");
				scanf("%f",&interest);
				
				printf("\nEnter year= ");
				scanf("%f",&year);
				
				if(princpal!=0 || interest!=0 || year!=0){
					
					si=(princpal*interest*year)/100;
					
					printf("\n\t\tSimple Interest is= Rs.%f",si);
				}
				else{
					
					printf("\n\n\t\tPlease enter the values!");
				}
				
				printf("\n\n\n\t\tDo you want to Exit? y/n ");
				scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					fordelay(100000000);
					goto restart;	
				}
				else{
					goto end;
				}
				break;
				
			case 6:
														//calculator
				recalculate:
					
				system("cls");
				
				printf("\n\t1) Addition \t2) Subtraction \t3)Multiplication \n\n \t4)Division \n\n\t\tEnter your choice:-");
				
				scanf("%d",&calc);
				
				printf("Enter first no:- ");
				scanf("%f",&a);
				
				printf("Enter second no:-");
				scanf("%f",&b);
				
				switch(calc){
					
					case 1:
						printf("Addition of %f and %f is= %f\n",a,b,a+b);
						break;
					
					case 2:
						printf("Subtration of %f and %f is= %f\n",a,b,a-b);
						break;
					
					case 3:
						printf("Multiplication of %f and %f is= %f\n",a,b,a*b);
						break;
					
					case 4:
						printf("Division of %f and %f is= %f\n",a,b,a/b);
						break;
							
					default:
						printf("Please Enter your choice!\n");
						break;		
				}
				
					printf("\n\t\tPress 0 to Reuse calculator\n\t\tDo you want to Exit? y/n ");
					scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					
					goto restart;	
				}
				else if(ans[2]=='0'){
					goto recalculate;
				}
				else{
					goto end;
				}
				
				break;
						
									
			end:
    			default:
    				
				printf("\nThank you for using SBI\n");
				
				
				for (i = 1; i <= 10;i++){
					fordelay(100000000);
					printf(".");
				}
					
			    break;		
		}
	
		//If pin is false
	}else{
		
		printf("\n\t\tWrong Pin!!!\n");
		
		printf("\n\n\n\t\tDo you want to continue? y/n ");
				scanf("%s",&ans);
				
				if(ans[0]=='y' || ans[1]=='Y'){
					fordelay(100000000);
					goto retype;	
				}
					
		}
		
		return 0;
}

void fordelay(int j)
{   int i,k;

    for(i=0;i<j;i++)
    
         k=i;
}





















