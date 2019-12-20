library(digest)
m=50
filter = rep(0,m)
no_of_hashfunction<-4
logged_in=c("shubham","parth","shivam","hasrh","rohit","shivdutt","rahul","ramesh","monti","ankita")
not_logged_in=c("harshan","varsha","gaurav","rohitawa","shurbhi","shivdutt","sonu","modiji","amitshah","vicky")
hash_function<-function(value,seed)
{
  x<-digest(object=value,algo='murmur32',serialize = TRUE,seed=seed)
  y=paste('0x',x,sep="")
  index<-as.numeric(y)%%m
  return(index)
}

for(i in 1:length(logged_in))
{
 for(j in 1:no_of_hashfunction)
 {
   filter[hash_function(logged_in[i],j)+1]<-1
 }
}
check<-function(value)
{
  for(i in 1:no_of_hashfunction)
  {
    index<-hash_function(value,i)
    index<-index+1
    if(filter[index]==0)
    {
      return(FALSE)
    }
  }
  return(TRUE)
}
test_data=c(logged_in[1:3],not_logged_in)
test_data

for(i in 1:length(test_data))
{
  if(check(test_data[i]))
  {
    if(test_data[i] %in% not_logged_in)
    {
      print("Its a false positive with");
      density0<-exp(-(2*10)/m)
      density1<-1-density0
      probability<-density1**2#where 2 is no of hash function
      print(probability*100)
    }
    else
    {
      print("URL is clicked previoulsy")
    }
    
  }
  else
  {
    print("this url is not clicked--")
  }
}

