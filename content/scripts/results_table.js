function makeTable(filePath, id) {
  fetch(filePath).then(r => r.text()).then(data => {
      const tabulated = data.split('\n').map(row => row.split('\t'));

      const trs = tabulated.map(row => {
          const tr = document.createElement('tr');

          row.forEach(col => {
              const td = document.createElement('td');
              td.textContent = col;
              tr.appendChild(td);
          });

          return tr;
      });

      const table = document.createElement('table');
      const thead = document.createElement('thead');
      thead.appendChild(trs.shift());

      const tbody = document.createElement('tbody');
      trs.forEach(tr => tbody.appendChild(tr));

      table.appendChild(thead);
      table.appendChild(tbody);

      document.getElementById(id).appendChild(table);
  })
}