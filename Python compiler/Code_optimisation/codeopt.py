f = open("inp.txt","r")

list_of_lines = f.readlines()
dictValues = dict()
constantFoldedList = []
print("Quadruple form after Constant Folding")
print("-------------------------------------")
for i in list_of_lines:
    i = i.strip("\n")
    op,arg1,arg2,res = i.split()
    arg1_type=arg1.isdigit() or arg1 in ["True" or "False"]
    arg2_type=arg2.isdigit() or arg2 in ["True" or "False"]
    if(op in ["+","-","*","/","and","or","==",">","<",">=","<="]):
        if( arg1_type and arg2_type):
            result = eval(arg1+" "+op+" "+arg2)
            dictValues[res] = str(result)
            print("=",result,"NULL",res)
            constantFoldedList.append(["=",result,"NULL",res])
        elif arg1_type:
            if(arg2 in dictValues):
                result = eval(arg1+" "+op+" "+str(dictValues[arg2]))
                dictValues[res] = str(result)   
            print(op,arg1,arg2,res)
            constantFoldedList.append([op,arg1,arg2,res])
        elif arg2_type:
            if(arg1 in dictValues):
                result = eval(dictValues[arg1]+" "+" "+op+" "+arg2)
                dictValues[res] = str(result)
            print(op,arg1,arg2,res)
            constantFoldedList.append([op,arg1,arg2,res])
        else:
            flag1=0
            flag2=0
            arg1Res = arg1
            if(arg1 in dictValues):
                arg1Res = dictValues[arg1]
                flag1 = 1
            arg2Res = arg2
            if(arg2 in dictValues):
                arg2Res = dictValues[arg2]
                flag2 = 1
            if(flag1==1 and flag2==1):
                result = eval(arg1Res+" "+op+" "+" "+arg2Res)
                dictValues[res] = str(result)
            print(op,arg1,arg2,res)
            constantFoldedList.append([op,arg1,arg2,res])
            
    elif(op=="="):
        if arg1_type:
            dictValues[res]=arg1
            print("=",arg1,"NULL",res)
            constantFoldedList.append(["=",arg1,"NULL",res])
        else:
            if(arg1 in dictValues):
                dictValues[res]=dictValues[arg1]
            print("=",arg1,"NULL",res)
            constantFoldedList.append(["=",arg1,"NULL",res])
    
    else:
        print(op,arg1,arg2,res)
        constantFoldedList.append([op,arg1,arg2,res])

def search(j,lst):
    for i in range(j):
    	if lst[i][0] in ["+","-","*","/","and","or","==",">","<",">=","<="]:
            if lst[i][1]==lst[j][1] and lst[i][2]==lst[j][2] and lst[i][0]==lst[j][0]:
                return i
    return -1
print("\n")


print("\n")
print("After common sub-expression elimination:")
print("------------------------------")
dump=dict()
for i in range(len(constantFoldedList)):
    if constantFoldedList[i][0] in ["+","-","*","/","and","or","==",">","<",">=","<="]:
        g=search(i,constantFoldedList)
        if g!=-1:
            dump[constantFoldedList[i][3]]=constantFoldedList[g][3]
            constantFoldedList[i][3]=constantFoldedList[g][3]
    if constantFoldedList[i][1] in dump:
        constantFoldedList[i][1]=dump[constantFoldedList[i][1]]
    if constantFoldedList[i][2] in dump:
        constantFoldedList[i][2]=dump[constantFoldedList[i][2]]    
    print(constantFoldedList[i][0],constantFoldedList[i][1],constantFoldedList[i][2],constantFoldedList[i][3])

print("\n")
print("After constant propogation - ")
print("------------------------------")
for i in constantFoldedList:
    if i[0] in ["+","-","*","/","and","or","==",">","<",">=","<="]:
        arg1_type=i[1].isdigit() or i[1] in ["True" or "False"]
        arg2_type=i[2].isdigit() or i[2] in ["True" or "False"]
        if not arg1_type:
            if i[1] in dictValues:
                i[1]=dictValues[i[1]]
                arg1_type=True
        if not arg2_type:
            if i[2] in dictValues:
               i[2]=dictValues[i[2]]
               arg2_type=True
        if arg1_type and arg2_type:
            result=eval(i[1]+" "+i[0]+" "+i[2])
            dictValues[i[3]]=str(result)
            i[0]="="
            i[1]=result
            i[2]="NULL"
    elif i[0] == "=":
        if i[1] in dictValues:
            i[1]=dictValues[i[1]]
    elif i[0]=="not":
        arg1_type=i[1].isdigit() or i[1] in ["True" or "False"]
        if not arg1_type:
            result=eval(i[0]+" "+dictValues[i[1]])
            i[1]=dictValues[i[1]]
        dictValues[i[3]]=i[1]       
    print(i[0],i[1],i[2],i[3])

print("\n")
print("Deadcode Elimination ")
print("------------------------------")
q=-1
i=0
while i in range(len(constantFoldedList)):
    if constantFoldedList[i][0]=="Label":
        q=i+1
        while q<len(constantFoldedList) and constantFoldedList[q][0]!="not":
           q+=1
        if q>=len(constantFoldedList):
    	        break
        if constantFoldedList[q][1]=="False":
    	    while q<len(constantFoldedList) and constantFoldedList[q][0]!="Label":
    	        q+=1
    	    if q>=len(constantFoldedList):
    	        break
    	    i=q
    print(constantFoldedList[i][0],constantFoldedList[i][1],constantFoldedList[i][2],constantFoldedList[i][3])
    i+=1 

