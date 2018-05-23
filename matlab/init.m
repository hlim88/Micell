function y = init(x)
   y = nan(size(x));
   y(-1<=x<=1) = 1;
   y(x > 1) = 0;
   y(x < -1) = 0;
end
