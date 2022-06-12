x=[1, 2, 2.5, 4, 6, 8, 8.5];
y=[0.4, 0.7, 0.8, 1.0, 1.2, 1.3, 1.4];
% We want a curve of the form y=Ax^b, using the Gauss-Newton with initial guesses of A=1,b=1
sol=[2;2];
% r=y-Ax^b
% dr^2/da=2x^b *r
% dr^2/db=-Ax^b * lnb
% Intitialise the Jacobian matrix
J=zeros(7,2);
r=zeros(7,1);
for j=1:500
for i=1:7
r(i,1)=(y(i)-sol(1,1)* (x(i)^sol(2,1)))^2;
J(i,1)=-2*sol(1,1)*(x(i)^(2*sol(2,1)));
J(i,2)=-(x(i)^2*sol(1,1)*sol(1,1)*log(x(i))*(2*sol(2,1)));
end
sol=sol + pinv(J)*r;
end
disp("The value A is :"),disp(sol(1,1));
disp("The value of b is :"),disp(sol(2,1)); 
