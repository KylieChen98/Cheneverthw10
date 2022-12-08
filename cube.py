def cb(x):
  return x*x*x

for i in range(20):
  if i%2 == 0:
    print i
  else:
    print cb(i)
