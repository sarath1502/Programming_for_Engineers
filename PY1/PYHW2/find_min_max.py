length=int(input())
for i in range(length):
     print( "Case ",i,":",sep='')
     ipt = input();
     numbers = ipt.split(' ')
     numbers = list(map(int,numbers))
     max=0;
     min=0;
     for j in range(len(numbers)):
         if(numbers[j]>max):
             max=numbers[j]
         if(numbers[j]<min):
             min=numbers[j]
     print("Min: ",min,sep='')
     print("Max: ",max,sep='')


        

