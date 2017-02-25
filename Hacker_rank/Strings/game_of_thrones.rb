str = gets.chomp

h = Hash.new

for i in 0...str.length
  if h.key? str[i]
    h[str[i]] += 1
  else
    h[str[i]] = 1
  end
end

odds = 0

h.keys.each { |key| odds += 1 if h[key].odd?  }

if odds == 1 || odds == 0
  puts "YES"
else
  puts "NO"
end
