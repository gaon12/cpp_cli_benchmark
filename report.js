(async function () {
  const systemEl = document.getElementById('system');
  const timesEl = document.getElementById('times');
  const checksEl = document.getElementById('checks');

  function addCheck(text, cls) {
    const li = document.createElement('li');
    li.textContent = text;
    if (cls) li.className = cls;
    checksEl.appendChild(li);
  }

  try {
    const res = await fetch('./result.json', { cache: 'no-store' });
    if (!res.ok) throw new Error('result.json을 읽지 못했습니다.');
    const data = await res.json();

    const sys = data.system || {};
    const measured = data.measured_at || {};
    const rows = [
      ['CPU', sys.cpu_name || '-'],
      ['GPU', sys.gpu_name || '-'],
      ['RAM(GB)', String(sys.ram_size_gb ?? '-')],
      ['Windows bits', String(sys.windows_bits ?? '-')],
      ['측정 시각', `${measured.year ?? '-'}-${measured.month ?? '-'}-${measured.day ?? '-'} ${measured.hour ?? '-'}:${measured.minute ?? '-'}`]
    ];
    rows.forEach(([k, v]) => {
      const dt = document.createElement('dt');
      dt.textContent = k;
      const dd = document.createElement('dd');
      dd.textContent = v;
      systemEl.appendChild(dt);
      systemEl.appendChild(dd);
    });

    const times = data.times_ms || {};
    Object.entries(times).forEach(([name, value]) => {
      const tr = document.createElement('tr');
      const n = document.createElement('td');
      n.textContent = name;
      const t = document.createElement('td');
      t.textContent = String(value);
      tr.appendChild(n);
      tr.appendChild(t);
      timesEl.appendChild(tr);
    });

    const thresholds = { plus: 1000, pi: 1000, upscale: 1000, compress: 1000, surd_e: 1000, decrypt_zip: 1000, download: 100 };
    let hasBad = false;
    Object.entries(thresholds).forEach(([k, min]) => {
      const v = Number(times[k]);
      if (!Number.isFinite(v)) {
        hasBad = true;
        addCheck(`${k}: 숫자가 아니거나 누락되었습니다.`, 'bad');
      } else if (v < min) {
        hasBad = true;
        addCheck(`${k}: ${v}ms (임계치 ${min}ms 미만)`, 'warn');
      }
    });
    if (!hasBad) addCheck('기본 이상치 검사를 통과했습니다.', 'good');
  } catch (err) {
    addCheck(`오류: ${err.message}`, 'bad');
  }
})();
