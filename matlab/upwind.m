% [u,x,t] = upwind(@f,t_0,t_f,npoints,cfl)
%
% solves the scalar advection equation u_t + u_x = 0 on [-2,2] 
% using 1st order upwind finite difference
%
% f is the function that contains the initial data

function [u,x,t] = upwind(f,t_0,t_f,npoints,cfl,time_plot)

tic

% define the mesh in space
dx = 4/npoints;
x = -2:dx:2;
x = x';

% define the mesh in time
dt = (t_f-t_0)/npoints;
t = t_0:dt:t_f;

%cfl number
v = cfl;

% choose the wave number of the initial data and give its decay rate
u = zeros(npoints+1,npoints+1);
u(:,1) = f(x);

% Upwind scheme
%
% u_new(j) = u_old(j) - C*(u_old(j)-u_old(j-1))
% where C is cfl condtion v dt/dx

for j=1:npoints
    for k=2:npoints+1
        u(k,j+1) = u(k,j)-v*(u(k,j)-u(k-1,j));
    end
    % u(1,j+1) = u(1,j) - mu*(u(1,j)-u(0,j))
    % recall that u(1)==u(N+1) and u(0)==u(N)
    u(1,j+1)=u(1,j)-v*(u(1,j)-u(npoints,j));
end

toc

plot(x,u(:,time_plot),'LineWidth',2);

end
