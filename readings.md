---
title: Readings
layout: single
category: Readings
toc: true
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true

---


* Week 2
  * [http://www.tigoe.com/pcomp/code/circuits/understanding-electricity/](http://www.tigoe.com/pcomp/code/circuits/understanding-electricity/)
  * [https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law/all](https://learn.sparkfun.com/tutorials/voltage-current-resistance-and-ohms-law/all)
* Week 3
  * [https://learn.sparkfun.com/tutorials/analog-vs-digital/all](https://learn.sparkfun.com/tutorials/analog-vs-digital/all)
  * [https://learn.sparkfun.com/tutorials/pulse-width-modulation/all](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)
  * [https://www.youtube.com/watch?v=GQLED3gmONg](https://www.youtube.com/watch?v=GQLED3gmONg)




{% capture dates_string %}
  {% include /functions/calc_week_dates.html %}
{% endcapture %}
{% assign dates_array = dates_string | split: '::'%}	



{% assign all_readings = site.readings | group_by: 'week' %}
{% for week in all_readings %}
{% assign index = week.name | times: 1 %} 
{% assign current_dates = dates_array[index] | split: '|' %}

<h2 id="week_{{ week.name }}">Week {{ week.name }} ({{current_dates[2] | strip}} - {{current_dates[3] | strip}})<a class="header-link" href="#week_{{ week.name }}" title="Permalink"></a></h2>
<ul>
    {% assign items = week.items | sort: 'order' %}
    {% for item in items %}
    <li><a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a></li>
    {% endfor %}
</ul>

{% endfor %}
{% capture my_include %}{% include_relative _readings/week03.md %}{% endcapture %}
{{ my_include | markdownify }}
{% include_relative _readings/week03.md %}