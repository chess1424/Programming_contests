str_1 = gets.chomp
str_2 = gets.chomp
h     = Hash.new
ans   = 0

for i in 0 ... str_1.length
  if h.key? str_1[i]
    h[str_1[i]] += 1
  else
    h[str_1[i]] = 1
  end
end

for i in 0 ... str_2.length
  if h.key? str_2[i]
    h[str_2[i]] -= 1
  else
    h[str_2[i]] = -1
  end
end

h.keys.each {|key| ans += h[key].abs}

puts ans
