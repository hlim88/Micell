% [u,x,t] = lax_friedrichs(@f,t_0,t_f,npoints,cfl)
%
% solves the heat equation u_t + u_x = 0 on [-2,2] 
% using Lax-Friedrichs
%
% f is the function thatcontains the initial data

function [u,x,t] = lax_friedrichs(f,t_0,t_f,npoints,cfl,time_plot)

tic

% define the mesh in space
dx = 4/npoints;
x = -2:dx:2;
x = x';

% define the mesh in time
dt = (t_f-t_0)/npoints;
t = t_0:dt:t_f;

%cfl factor
v = cfl;

% choose the wave number of the initial data and give its decay rate
u = zeros(npoints+1,npoints+1);
u(:,1) = f(x);

% Lax-Friedrichs scheme:
%
% u_new(j) = (u_old(j-1)+u_old(j+1))/2 - C/2*(u_old(j+1)-u_old(j-1))
% where C is cfl condition v dt/dx

for j=1:npoints
    for k=2:npoints
        u(k,j+1) = (u(k+1,j)+u(k-1,j))/2-(v/2)*(u(k+1,j)-u(k-1,j));
    end
    % I code in the exact values at the endpoints.
    k=1;
    % u(k-1) = u(0) == u(N)
    u(k,j+1)=(u(k+1,j)+u(npoints,j))/2-(v/2)*(u(k+1,j)-u(npoints,j));
    k = npoints+1;
    % u(k+1) = u(N+2) == u(2)
    u(k,j+1)=(u(2,j)+u(k-1,j))/2-(v/2)*(u(2,j)-u(k-1,j));
end


toc
plot(x,u(:,time_plot),'LineWidth',2);

end