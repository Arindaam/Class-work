function [L,U]=LU_dec()
    a=evstr(x_matrix('enter a  3x3 matrix ',rand(3,3)))
    U=a
    m=det(U(1,1));
    n=det(U(2,1));
    b=n/m;
    U(2,:)=U(2,:) - U(1,:)/(m/n);
    n=det(U(3,1));
    c=n/m;
    U(3,:)=U(3,:) - U(1,:)/(m/n);
    m=det(U(2,2));
    n=det(U(3,2));
    d=n/m;
    U(3,:)=U(3,:) - U(2,:)/(m/n);
    L=[1,0,0;b,1,0;c,d,1];
    disp(L,"The lower triangular matrix  L=")
    disp(U,"The upper triangular matrix  U=")
endfunction

LU_dec()

