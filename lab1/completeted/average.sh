sum=0
count=$#

for arg in "$@"; do
    sum=$((sum + arg))
done

avg=$((sum / count))

echo "Количество: $count"
echo "Среднее арифметическое: $avg"