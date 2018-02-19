length=int(input())
for i in range(length):
     print( "Case ",i,":",sep='')
     n=int(input())
     pi=0
     for j in range(n):
         pi=pi+((-1)**j/(2*j+1))
     pi=pi*4
     print("Pi estimated as: ",'{:.8f}'.format(pi),sep='')


         

