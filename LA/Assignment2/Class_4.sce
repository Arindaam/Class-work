clc;clear;close;
n=3
disp("Enter matrix A")
for i=1:n
    for j=1:n
        a(i,j)=input("Enter")
    end
end
disp('matrix is ')
disp(a)
a(2,:)=a(2,:)-(a(2,1)/a(1,1))*a(1,:)
a(3,:)=a(3,:)-(a(3,1)/a(1,1))*a(1,:)
disp(a)
a(3,:)=a(3,:)-(a(3,2)/a(2,2))*a(2,:)
disp(a)
a(1,:)=a(1,:)/a(1,1)
a(2,:)=a(2,:)/a(2,2)
disp(a)
for i=1:n
    for j=i:n
        if(a(i,j)<>0)
            disp('is a pivot element ',j,'column')
            break
        end
    end
end
