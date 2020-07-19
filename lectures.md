---
title: Lectures
category: lectures
layout: single
classes: wide

---


{% capture dates_string %}
  {% include /functions/calc_week_dates.html %}
{% endcapture %}
{% assign dates_array = dates_string | split: '::'%}	




{% assign all_lectures = site.lectures | group_by: 'week' %}
{% for week in all_lectures %}
{% assign index = week.name | times: 1 %} 
{% assign current_dates = dates_array[index] | split: '|' %}

<h2>Week - {{ week.name }} ({{current_dates[2] | strip}} - {{current_dates[3] | strip}})</h2>
<ul>
    {% assign items = week.items | sort: 'order' %}
    {% for item in items %}
    <li><a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a></li>
    {% endfor %}
</ul>

{% endfor %}
