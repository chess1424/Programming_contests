n      = gets.chomp.to_i
str    = gets.chomp
$h     = {'A' => 0, 'G' => 0, 'T' => 0, 'C' =>0}
$limit = n/4

def ok
  ans = true
  $h.keys.each{ |key| ans = false if $h[key] > $limit }
  ans
end

str.each_char{ |c| $h[c] += 1 }

if ok
  puts 0
else
  j = 0
  ans = n
  
  for i in 0 ... str.length
    while j < n && !ok
      $h[str[j]] -= 1
      j += 1
    end

    ans = [ans , j-i].min if ok
    $h[str[i]] += 1
  end

  puts ans
end

