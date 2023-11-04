fun main() {
    repeat(readln().toInt()) {
        val (n, k) = readln().split(' ').map { it.toInt() }
        val l = readln().split(' ').map { it.toInt() }
        val r = readln().split(' ').map { it.toInt() }

        var ans = 2e9.toInt()
        var cntShort = 0
        var lenLong = 0
        for (i in 0 until n) {
            val curLen = r[i] - l[i] + 1
            if(curLen > 1)
                lenLong += curLen
            else
                cntShort++

            if (lenLong < k) {
                if (lenLong + cntShort >= k) {
                    val cntSegs = (i + 1 - cntShort) + (k - lenLong)
                    ans = minOf(ans, r[i] + 2 * cntSegs)
                }
            }
            else {
                ans = minOf(ans, r[i] - (lenLong - k) + 2 * (i + 1 - cntShort))
                break
            }
        }
        if (ans == 2e9.toInt())
            ans = -1
        println(ans)
    }
}