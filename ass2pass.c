#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char label[10],opcode[10],operand[10],code[10],nmemonics[10];
	int locctr,i=0,error,start_add,length;
	FILE *f1,*f2,*f3.*f4;
	f1 = fopen("input.txt","r");
	f3 = fopen("symtab.txt","w");
	f2 = fopen("optab.txt","w");
	f4 = fopen("output.txt","w");
	fscanf(f1,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		locctr = atoi(operand);
		start_add = locctr;
		fprintf(f4,"%s\t%s\t%s\n",label,opcode,operand);
		fscanf(f1,"%s%s%s",label,opcode,operand);
	}
	else
	{
		locctr=0;
		start_add=0;
	}
	
	while(strcmp(opcode,"END")!=0)
	{   fprintf(f4,"%d",locctr);
	
		if(strcmp(label,"**")!=0)
		{
			fprintf(f3,"%s\t%d\n",label,locctr);
		}
		fscanf(f2,"%s%s",code,nmemonic);
		while(strcmp(code,"END")!=0)
    	{
     		if(strcmp(opcode,code)==0)
     		{
      			locctr+=3;
      			break;
     		}
     		fscanf(f2,"%s%s",code,nmemonic);
    	}
		if(strcmp(opcode,"WORD")==0)
			locctr= locctr+3;
		else if(strcmp(opcode,"BYTE")==0)
			{
			if(operand[0] == 'C')
				locctr = locctr+strlen(operand)-3;
			else
				locctr = locctr + (strlen(operand)-3)/2;
			}
		else if(strcmp(opcode,"RESW")==0)
			locctr = locctr + atoi(operand)*3;
		else if(strcmp(opcode,"RESB")==0)
			locctr = locctr+atoi(operand);
			
		fprintf("%s\t%s\t%s",label,opcode,operand);
		fscanf("%s\t%s\t%s",label,opcode,operand);
		
	}
	fprintf(f4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	length = locctr - start_add;
	printf("\nLength of the program is %d",length);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
  
}
	


