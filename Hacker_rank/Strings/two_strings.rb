t = gets.chomp.to_i

t.times do
  str_1       = gets.chomp
  str_2       = gets.chomp 
  isSubstring = false

  str_1.each_char do |c|
    if str_2.include? c
      isSubstring = true
      break
    end
  end

  puts isSubstring ? "YES" : "NO"
  
end
