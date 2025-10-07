document.getElementById("analyzeBtn").addEventListener("click", async () => {
  const pw = document.getElementById("pw").value;

  const res = await fetch("/analyze", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ password: pw })
  });

  const data = await res.json();
  const result = document.getElementById("result");

  result.innerHTML = `
    <p><strong>Valid:</strong> ${data.valid ? "✅ Yes" : "❌ No"}</p>
    <p><strong>Score:</strong> ${data.score}</p>
  `;
});
