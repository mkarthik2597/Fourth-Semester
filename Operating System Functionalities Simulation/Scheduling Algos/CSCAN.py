def RMOVE(count):
    global k
    i=arr.index(curr_head)
    sum=0

    while(count<N):
        if i==N-1:
            print "%d->%d %d"%(arr[N-1],tot_cyl-1,tot_cyl-arr[N-1]-1)
            sum+=tot_cyl-arr[N-1]-1
            sequence[k]=tot_cyl-1
            k+=1

            i=0

            print "%d->%d %d"%(tot_cyl-1,0,0)
            sequence[k]=0
            k+=1
            print "%d->%d %d"%(0,arr[0],tot_cyl-arr[0])
            sequence[k]=arr[0]
            k+=1
            sum+=tot_cyl-arr[0]
            count+=1

        print "%d->%d %d"%(arr[i],arr[i+1],arr[i+1]-arr[i])
        sequence[k]=arr[i+1]
        k+=1
        sum+=arr[i+1]-arr[i]
        count+=1
        i+=1

    return sum

def LMOVE(count):
    global k
    i=arr.index(curr_head)
    sum=0

    while(count<N):
        if i==0:
            print "%d->%d %d"%(arr[0],0,arr[0]-0)
            sum+=arr[0]-0
            sequence[k]=0
            k+=1

            i=N-1

            print "%d->%d %d"%(0,tot_cyl-1,0)
            sequence[k]=tot_cyl-1
            k+=1
            print "%d->%d %d"%(tot_cyl-1,arr[N-1],arr[N-1])
            sequence[k]=arr[N-1]
            k+=1
            sum+=arr[N-1]
            count+=1

        print "%d->%d %d"%(arr[i],arr[i-1],arr[i]-arr[i-1])
        sequence[k]=arr[i-1]
        k+=1
        sum+=arr[i]-arr[i-1]
        count+=1
        i-=1

    return sum


RIGHT=0
LEFT=1

print "Enter Total no. of cylinders, curr_head and prev head:"
tot_cyl,curr_head,prev_head=map(int,raw_input().split())

print "Enter total no. of requests:"
N=int(raw_input())+1

print "Enter the requests:"
temp=raw_input()
arr=map(int,temp.split())
arr.append(curr_head)
arr.sort()

DIR=RIGHT if prev_head<curr_head else LEFT

sum=0
count=1
k=0
sequence={}

sequence[k]=curr_head
k+=1

if DIR==RIGHT:
    sum+=RMOVE(count)
    print "\nTotal moves=%d"%(sum)
else:
    sum+=LMOVE(count)
    print "\nTotal moves=%d"%(sum)

print sequence
