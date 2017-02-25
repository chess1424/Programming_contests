t = gets.chomp.to_i

t.times do
  str     = gets.chomp
  deleted = false
  
  l = 0
  r = str.length - 1

  while l <= r do
    if str[l] != str[r]    
      deleted  = true
      break
    end
    l += 1
    r -= 1 
  end

  if !deleted
    puts "-1"
  else
    l_original    = l
    r_original    = r
    r            -= 1
    isPalindrome  = true

    while l <= r do
      if str[l] != str[r]
        isPalindrome = false
        break
      end
      l += 1
      r -= 1
    end

    puts isPalindrome ? r_original : l_original
  end    
end
