t = gets.chomp.to_i

t.times do
  str = gets.chomp
  left = ans = 0
  right = str.length - 1

  while left <= right do
    ans += ( str[left].ord - str[right].ord ).abs
    left += 1
    right -= 1
  end

  puts ans
end
