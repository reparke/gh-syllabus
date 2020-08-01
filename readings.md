---
title: Pre-Lecture Activities / Reading / Video
layout: single
category: Readings
toc: true
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true

---


{% capture dates_string %}
  {% include /functions/calc_week_dates.html %}
{% endcapture %}
{% assign dates_array = dates_string | split: '::' %}	


<p><i>To be completed prior to coming to lecture in a given week</i></p>

{% assign all_readings = site.readings | group_by: 'week' %}
{% for week in all_readings %}
{% assign index = week.name | times: 1 %} 
{% assign current_dates = dates_array[index] | split: '|' %}
{% if index != 16 %}

<ul>
    {% assign items = week.items | sort: 'order' %}
    {% for item in items %}
    <li><a href="{{ site.baseurl }}{{ item.url }}">Week {{ week.name }}</a> (complete prior to <b>{{current_dates[2] | strip}})</b></li>
    {% endfor %}
</ul>
{% endif %}
{% endfor %}
