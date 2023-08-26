import mysql.connector as ch
conn=ch.connect(host='localhost',user="root",passwd='admin',database='project')
if conn.is_connected()==1:
    print("connected")
else:
    print("not connected")
    
cur=conn.cursor()
def menu():
    print("Bus Reservation System")
    print("1. Check Bus Schedule")
    print("2. Book Ticket")
    print("3. Cancel Ticket")
    print("4. Exit")
    ch=int(input("Enter choice: "))
    if ch==1:
        schedule()
    elif ch==2:
        book()
    elif ch==3:
        cancel()
    elif ch==4:
        return("Thank You.")

def schedule():
    st='Select * from schedule'
    cur.execute(st)

def book():
    l=[]
    a=input("Enter name")
    l.append(a)
    b=input("Enter age")
    l.append(b)
    c=input("Enter Gender : M/F")
    l.append(c)
    d=input("Enter bus no")
    l.append(d)
    cur.execute("Insert into {} values{}".format(d,l))
    cur.commit()

def cancel():
    a=input("Enter name: ")
    d=input("Enter bus no")
    cur.execute("Delete from {} where name={}".format(d,a))
    cur.commit()
    
menu()