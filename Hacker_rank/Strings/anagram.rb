t = gets.chomp.to_i

t.times do
  hash = Array.new(26,0);
  ans = 0;

  str = gets.chomp

  if str.length.odd?
    puts "-1"
  else
    for i in str.length / 2 .. str.length-1
      hash[str[i].ord - 'a'.ord] += 1
    end

    for i in 0 .. str.length/2 - 1
      if hash[str[i].ord - 'a'.ord] == 0
        ans += 1
      else
        hash[str[i].ord - 'a'.ord] -= 1
      end
    end

    puts ans
  end
end
