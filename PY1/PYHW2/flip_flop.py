length=int(input())
for i in range(length):
     print( "Case ",i,":",sep='')
     ipt = input();
     numbers = ipt.split(' ')
     numbers = list(map(int,numbers))
     start=numbers[0]
     end=numbers[1]+start
     a=numbers[2]
     b=numbers[3]
     for i in range(start,end,1):
         if(i%a==0):
             print("flip",sep='',end='')
         if(i%b==0):
             print("flop",sep='',end='')
         if(i%a!=0 and i%b!=0):
             print(i,sep='',end='')
         print()

     