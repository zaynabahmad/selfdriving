# p=[]
# n=5
# for i in range(n):
# 	p.append(1/n)
# print(p)

####################3
# with phit and pmiss 

p=[0.2,0.2,0.2,0.2,0.2]
world=['green','red','red','green','green']
Z='red'
pHit=0.6  # red 
pMiss = 0.2  # green 

# for i in range(len(p)):
#     if i ==1 or i == 2 :
#         p[i]=p[i]*pHit
#     else :
#         p[i]=p[i]*pMiss

def sense (p,Z):
	q=[]
	for i in range(len(p)):
		hit=(Z==world[i])
		q.append(p[i]*(hit*pHit+(1-hit)*pMiss))
	sum_ = sum(q)
	for j in range(len(p)):
		q[j]=q[j]/sum_
	return q # which is the non normalize probablity 
    
#print (p) 
print (sense(p,Z))
print(sum(p))

