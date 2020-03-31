function []=gram_Schmidt()
    a=evstr(x_matrix('enter a  3x1 matrix ',rand(3,1)))
    b=evstr(x_matrix('enter a  3x1 matrix ',rand(3,1)))
    v1=a
    c=b'*v1
    d=v1'*v1
    p=(c/d)*v1
    v2=b-p
    disp(p,'-',b,'=')
    disp(v2,'=')
    disp("Thus orthogonal basis is:")
    disp(v2,v1)
endfunction
gram_Schmidt()
    
