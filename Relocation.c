 HomeSystem Software LabIMPLEMENTATION OF A RELOCATION LOADER in CS1207 SYSTEM SOFTWARE LAB
IMPLEMENTATION OF A RELOCATION LOADER in CS1207 SYSTEM SOFTWARE LAB
Learning|Tutorial12:17 AM
Aim
Perform the Relocation Loader using c program
Algorithm
Start the program
Include the necessary header file and variable
Open the two file for
fp1= relinput.dat and give read
fp2= reloutput.dat and give write
Read the content
Using while loop perform the loop until character is not equal to E
while(strcmp(input,"E")!=0)
If the character is H
Get the variable add, length, and input
Else if the character is T
Get the variable address and bitmask
And perform the for loop for starting zero to up to len
Get the opcode ,addr and assign relocbit to bitmask
If relocabit is zero
Then
actualadd=addr;
else
Add the addr and star value
Finally terminate the program
Source code program in c for Relocation Loader
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
void main()
{
char add[6],length[10],input[10],binary[12],bitmask[12],relocbit;
int start,inp,len,i,address,opcode,addr,actualadd;
FILE *fp1,*fp2;
clrscr();
printf("Enter the actual starting address : ");
scanf("%d",&start);
fp1=fopen("relinput.dat","r");
fp2=fopen("reloutput.dat","w");
fscanf(fp1,"%s",input);
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(fp1,"%s",add);
fscanf(fp1,"%s",length);
fscanf(fp1,"%s",input);
}
if(strcmp(input,"T")==0)
{
fscanf(fp1,"%d",&address);
fscanf(fp1,"%s",bitmask);
address+=start;
len=strlen(bitmask);
for(i=0;i<len;i++)
{
fscanf(fp1,"%d",&opcode);
fscanf(fp1,"%d",&addr);
relocbit=bitmask[i];
if(relocbit=='0')
actualadd=addr;
else
actualadd=addr+start;
fprintf(fp2,"%d\t%d%d\n",address,opcode,actualadd);
address+=3;
}
fscanf(fp1,"%s",input);
}
}
fclose(fp1);
fclose(fp2);
printf("FINISHED");
getch();
}

INPUT : RELINPUT.DAT
H 1000 200
T 1000 11001 14 1033 48 1039 90 1776 92 1765 57 1765
T 2011 11110 23 1838 43 1979 89 1060 66 1849 99 1477
E 1000

OUTPUT :
Enter the actual starting address :4000

RELOUTPUT.DAT
4000 144033
4003 484039
4006 901776
4009 921765
4012 574765
5011 234838
5014 434979
5017 894060
5020 664849
5023 991477