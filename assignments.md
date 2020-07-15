---
title: Assignments
layout: category
menuItem: Assignments
menuPosition: 3
classes: wide
---

{% if site.docsUrl != "" %}
You can download all required reading in the [Study materials]({{ site.docsUrl }}) at the faculty website.
{% endif %}



<ul>
{% assign syllabus = (site.assignments | sort: "number") %}
{% for week in syllabus %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">{{ week.title }}</a> 
  	(Due: <b>{{ week.date_due }}</b>)</li>
{% endfor %}
</ul>





