import re
import sys
def rem_comments(text):
    main_list=[]
    pat='#(.*)'
    for i in text:
        m=re.findall(pat,i)
        if m and text.index(i)!=0:   
            index=i.find(m[0])
            main_list.append(i[:index-1])
        else:
            main_list.append(i)
    return main_list

def if_rem(text): #Removes the if statement blocks. The occurence of if is flagged and lines are igmored till fi is encountered. 
    stack=[]
    main_list=[]     
    pat1="(\s)*if "
    pat2="fi(\s)*$"
    for i in text:
        m=re.findall(pat1,i)
        if not stack:
            if m:
                stack.append(m)
            else:
                main_list.append(i)
        else:
            n=re.findall(pat2,i)
            if m:
                stack.append(m)
            elif n:
                stack.pop()
    return main_list

def space_rem(text): # Removes blank lines and lines with just spaces
    main_list=[]
    pat='^(\s)*$'
    for i in text: 
        m=re.search(pat,i)
        if not m:
            main_list.append(i)
    return main_list                

def func_rem(text): #Deletes dummy functions
    flag=0
    count=0
    main_list=[]
    pat="(.)+\(\)"
    pat2='}'    
    for i in text:
        m=re.findall(pat,i)
        if m:
            flag=1
            main_list.append(i)
        elif flag==1:
            n=re.search(pat2,i)
            if n:
                flag=0
                if count==1:
                    main_list.pop()
                    main_list.pop()
                else:
                    main_list.append(i)
                count=0
            else:
                main_list.append(i)
                count+=1
        else:
            main_list.append(i)
    return main_list    

def aliasing(text): #A dictionary is used so as to delete any transitive redundant aliases. 
    a=dict()
    main_list=[]
    pat="alias (.+?)=\'(.+?)\'"
    for i in text:
        m=re.search(pat,i)
        if m:
            if m.group(1) in a.values():#Checks if the given alias is part of key-value pair and if so, the dictionary is updated to avoid transitive redundant aliases.
                
                for var,val in a.items():
                    if val==m.group(1):
                        a[var]=m.group(2)
            else:
                a[m.group(1)]=m.group(2)
    for i in text:
        m=re.search(pat,i)
        if m:
            if m.group(1) in a.keys():
                if m.group(2)==a[m.group(1)]:
                    main_list.append(i) 
                else:
                    p="alias "+m.group(1)+"='"+a[m.group(1)]+"'\n"
                    main_list.append(p)
                a.pop(m.group(1))
        else:
            main_list.append(i)
    return main_list

file1 = open(sys.argv[1], 'r') 
Lines = file1.readlines()
Step1=rem_comments(Lines)
Step2=space_rem(Step1)
Step3=if_rem(Step2)
Step4=aliasing(Step3)
Step5=func_rem(Step4)
file1=open("PES1201800274_A2.sh",'w')
file1.writelines(Step5)
file1.close()
file2 = open('PES1201800274_A2.sh', 'r')
print(file2.read(),end="") 
file2.close() 
