function []=gauss_jord()
   A=evstr(x_matrix('enter a  3x3 matrix ',rand(3,3)))
disp(A, "Matrix A : ")
Aug = [A,eye(n,n)];
for j=1:n-1
    for i=j+1:n
        Aug(i,j:2*n) = Aug(i,j:2*n)-Aug(i,j)/Aug(j,j)*Aug(j,j:2*n);
    end
end
for j=n:-1:2
    Aug(1:j-1,:)=Aug(1:j-1,:)-Aug(1:j-1,j)/Aug(j,j)*Aug(j,:);
end
for j=1:n
    Aug(j,:)=Aug(j,:)/Aug(j,j);
end
B=Aug(:,n+1:2*n)
disp("INVERSE OF A:")
disp(B)
endfunction
gauss_jord()
