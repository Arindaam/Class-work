import re
import sys
def task_c(texts): #SubtaskC, Searches for a specific tag content in xml file.
    count3=0
    pat = '(^|\s|>)(\+{5})?(\?\?\?)+(\*\*)+($|\s|<)|(^|\s|>)(\+{2})(\?\?)+(\*\*\*)+($|\s|<)' #Regex for the given patterns to be matched
    for text in texts:
        m = re.search(pat, text)
        if m :
            count3=count3+1
    return count3

def task_a(texts,tag):#SubtaskA, To find the number of a particular opening tag in the xml
    count2=0
    pat = "<"+tag+">"
    for text in texts:
        m = re.findall(pat, text)
        if m :
            for i in m:
                count2+=1
    return count2

def task_b(texts):#SubtaskB, To find number of unclosed tags
    stack=[]
    pat='<\w+>'
    pat1='</\w+>'
    pat2='<\w+>|</\w+>'
    count=0
    for i in texts:
        m = re.findall(pat2, i) #Finds all opening and closing tags in the xml file
        for j in m:
            if(re.search(pat,j)):
                stack.append(j)  #Opening tags are appended into a stack
            else:
                new=j.replace('/','')
                if new in stack: #This is to ensure invalid closing tags do not empty the opening tag stack
                    count=count+(len(stack)-stack.index(new)-1)
                    for p in range(len(stack)-1,stack.index(new)-1,-1):
                        stack.pop(p) #When a valid closing tag is encountered, tags are popped till the corresponding opening tag is found in the stack. 
    return count+len(stack)

def task_d(texts,tag):#SubtaskD, To find how many times a particular tag has more than 3 children.
    final_count=0 #The required count ie No of instances of given tag having more than 3 
    stack=[]
    flag=0
    pat2="<"+tag+">"
    pat="<\w+>"
    pat3="<\w+>(\s)*(\w)+(\s*|<\w)"
    pat1='<\w+>|</\w+>' 
    count=0 #Count of No. children of given tag
    for i in texts:
        m=re.findall(pat1,i) #Finds all opening and closing tags in the xml file
        if pat2 in m: #If given tag is found in a given line. This event is Flagged.
            flag=1
        if flag==1:
            for j in m:
                if(re.search(pat,j)):
                    stack.append(j) #All opening tags are appended into a stack
                    if(re.search(pat3,i)) and len(stack)>1 and stack[len(stack)-2]==pat2:
                            stack.pop(len(stack)-1) #If a child of Given tag is unclosed, that is recognised and popped immediately, child count is incremented 
                            count+=1
                else:
                    new=j.replace('/','')
                    if new in stack:
                        for p in range(len(stack)-1,stack.index(new)-1,-1): 
                            stack.pop(p) #When a closing tag is encountered, the corresponding opening tag and all the unclosed tags are popped. Only When the tag to be popped is after the given tag, it is a child of the given tag, hence in this case count is incremented.
                            if(len(stack)>0 and stack[len(stack)-1]==pat2):
                                count+=1
                        if new==pat2:
                            if(count>=3):
                                final_count+=1
                            count=0
                            if pat2 not in m[m.index(j):]: #If another opening tag for the given tag is not present in the same line, we exit the line and read next line.
                                flag=0
                                break
    return final_count

file1 = open(sys.argv[1], 'r') 
Lines = file1.readlines() 
a=input().split()
b=input()
c=input()
d=input().split()
print(task_a(Lines,a[1]))
print(task_b(Lines))
print(task_c(Lines))
print(task_d(Lines,d[1]))
file1.close()